/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:37:26 by jnoh              #+#    #+#             */
/*   Updated: 2022/11/24 17:38:56 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	ft_philo_printf(philo, "has taken a fork");
	pthread_mutex_lock(philo->rfork);
	ft_philo_printf(philo, "has taken a fork");
	philo->eat_count++;
	if (philo->eat_count == philo->info->num_must_eat)
		philo->info->finish_eat_cnt++;
	philo->last_eat = ft_gettime();
	ft_philo_printf(philo, "is eating");
	ft_sleep(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
}

static void	ft_philo_join(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->philo_num)
	{
		pthread_join(arg->philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < arg->philo_num)
	{
		pthread_mutex_destroy(&(arg->fork[i]));
		i++;
	}
	pthread_mutex_destroy(&(arg->print));
	ft_free(arg);
}

static void	*ft_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)(arg);
	if (philo->philo_id % 2)
		usleep(1000);
	while (!(philo->info->finish))
	{
		ft_philo_eat(philo);
		ft_philo_printf(philo, "is sleeping");
		ft_sleep(philo->info->time_to_sleep);
		ft_philo_printf(philo, "is thinking");
	}
	return (0);
}

void	ft_philo_check_finish(t_arg *arg)
{
	long long	time;
	int			i;

	while (!(arg->finish))
	{
		i = 0;
		time = ft_gettime();
		while (i < arg->philo_num)
		{
			if (time - arg->philo[i].last_eat >= arg->time_to_die)
			{
				ft_philo_printf(&(arg->philo[i]), "died");
				arg->finish = 1;
				return ;
			}
			i++;
		}
	}
}

void	*ft_philo_check_eatcnt(void *info)
{
	t_arg	*arg;

	arg = (t_arg *)(info);
	while (!(arg->finish))
	{
		if (arg->finish_eat_cnt >= arg->philo_num)
			arg->finish = 1;
	}
	return (NULL);
}

int	ft_philo_main(t_arg *arg)
{
	int			i;
	pthread_t	thread;

	i = 0;
	while (i < arg->philo_num)
	{
		if (pthread_create(&(arg->philo[i].thread), NULL, ft_routine, &(arg->philo[i])))
			return (1);
		i++;
	}
	if (arg->num_must_eat != -1)
		pthread_create(&thread, NULL, ft_philo_check_eatcnt, arg);
	ft_philo_check_finish(arg);
	ft_philo_join(arg);
	return (0);
}
