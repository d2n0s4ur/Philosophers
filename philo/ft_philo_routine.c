/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:37:26 by jnoh              #+#    #+#             */
/*   Updated: 2022/11/07 12:20:40 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	pthread_mutex_lock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

static void	*ft_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)(arg);
	if (philo->philo_id % 2)
		usleep(1000);
	while (!(philo->died))
	{
		ft_philo_eat(philo);
		// ft_philo_sleep(philo);
		// ft_philo_think(philo);
	}
	return (0);
}

int	ft_philo_main(t_arg *arg)
{
	int	i;

	i = 0;
	arg->time_init = ft_gettime();
	while (i < arg->philo_num)
	{
		arg->philo[i].philo_id = i + 1;
		if (pthread_create(&(arg->philo[i].thread), NULL, ft_routine, &(arg->philo[i])))
			return (1);
		i++;
	}
	return (0);
}
