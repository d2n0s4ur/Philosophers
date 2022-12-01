/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:37:26 by jnoh              #+#    #+#             */
/*   Updated: 2022/12/01 11:03:09 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_peek_fork(t_arg *arg, int fork_id)
{
	while (1)
	{
		pthread_mutex_lock(&(arg->fork_m[fork_id]));
		if (arg->fork[fork_id] == 0)
		{
			arg->fork[fork_id] = 1;
			pthread_mutex_unlock(&(arg->fork_m[fork_id]));
			break ;
		}
		pthread_mutex_unlock(&(arg->fork_m[fork_id]));
	}
}

static void	ft_drop_fork(t_arg *arg, int fork_id)
{
	while (1)
	{
		pthread_mutex_lock(&(arg->fork_m[fork_id]));
		if (arg->fork[fork_id])
		{
			arg->fork[fork_id] = 0;
			pthread_mutex_unlock(&(arg->fork_m[fork_id]));
			break ;
		}
		pthread_mutex_unlock(&(arg->fork_m[fork_id]));
	}
}

static void	ft_philo_eat(t_philo *ph)
{
	ft_peek_fork(ph->info, ph->lf);
	ft_philo_printf(ph, "has taken a fork");
	ft_peek_fork(ph->info, ph->rf);
	ft_philo_printf(ph, "has taken a fork");
	ph->cnt++;
	if (ph->cnt == ph->info->n_must_eat)
	{
		pthread_mutex_lock(&(ph->info->cnt_m));
		ph->info->finish_eat_cnt++;
		pthread_mutex_unlock(&(ph->info->cnt_m));
	}
	ft_philo_printf(ph, "is eating");
	pthread_mutex_lock(&(ph->last_m));
	ph->last_eat = ft_gettime();
	pthread_mutex_unlock(&(ph->last_m));
	ft_sleep(ph->info->t_to_eat);
	ft_drop_fork(ph->info, ph->rf);
	ft_drop_fork(ph->info, ph->lf);
}

static void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)(arg);
	if (philo->pid % 2)
		usleep(1000);
	while (!ft_philo_isfinish(philo->info))
	{
		ft_philo_eat(philo);
		ft_philo_printf(philo, "is sleeping");
		ft_sleep(philo->info->t_to_sleep);
		ft_philo_printf(philo, "is thinking");
	}
	return (0);
}

int	ft_philo_main(t_arg *arg)
{
	int			i;
	pthread_t	thread;

	i = 0;
	while (i < arg->ph_num)
	{
		if (pthread_create(&(arg->ph[i].tid), NULL, ft_routine, &(arg->ph[i])))
			return (1);
		i++;
	}
	if (arg->n_must_eat)
	{
		if (pthread_create(&thread, NULL, ft_philo_check_eatcnt, arg))
			return (1);
		pthread_join(thread, NULL);
	}
	ft_philo_check_finish(arg);
	ft_philo_join(arg);
	return (0);
}
