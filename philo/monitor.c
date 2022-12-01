/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:57:22 by jnoh              #+#    #+#             */
/*   Updated: 2022/12/01 11:02:59 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_isfinish(t_arg *arg)
{
	int	ret;

	pthread_mutex_lock(&(arg->finish_m));
	ret = arg->finish;
	pthread_mutex_unlock(&(arg->finish_m));
	return (ret);
}

void	ft_philo_check_finish(t_arg *arg)
{
	long long	time;
	int			i;

	while (!ft_philo_isfinish(arg))
	{
		i = 0;
		while (i < arg->ph_num)
		{
			pthread_mutex_lock(&(arg->ph[i].last_m));
			time = ft_gettime();
			if (time - arg->ph[i].last_eat >= arg->t_to_die)
			{
				pthread_mutex_unlock(&(arg->ph[i].last_m));
				ft_philo_printf(&(arg->ph[i]), "died");
				pthread_mutex_lock(&(arg->finish_m));
				arg->finish = 1;
				pthread_mutex_unlock(&(arg->finish_m));
				break ;
			}
			pthread_mutex_unlock(&(arg->ph[i].last_m));
			i++;
		}
	}
	return ;
}

void	*ft_philo_check_eatcnt(void *info)
{
	t_arg	*arg;

	arg = (t_arg *)(info);
	while (!ft_philo_isfinish(arg))
	{
		pthread_mutex_lock(&(arg->cnt_m));
		if (arg->finish_eat_cnt >= arg->ph_num)
		{
			pthread_mutex_unlock(&(arg->cnt_m));
			pthread_mutex_lock(&(arg->finish_m));
			arg->finish = 1;
			pthread_mutex_unlock(&(arg->finish_m));
			break ;
		}
		else
			pthread_mutex_unlock(&(arg->cnt_m));
	}
	return (0);
}

void	ft_philo_join(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->ph_num)
	{
		pthread_join(arg->ph[i].tid, NULL);
		i++;
	}
	i = 0;
	while (i < arg->ph_num)
	{
		pthread_mutex_destroy(&(arg->fork_m[i]));
		pthread_mutex_destroy(&(arg->ph[i].last_m));
		i++;
	}
	pthread_mutex_destroy(&(arg->print_m));
	pthread_mutex_destroy(&(arg->finish_m));
	pthread_mutex_destroy(&(arg->cnt_m));
	ft_free(arg);
}
