/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:08:53 by jnoh              #+#    #+#             */
/*   Updated: 2022/11/10 20:58:08 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_free(t_arg *arg)
{
	if (arg->philo)
		free(arg->philo);
	if (arg->fork)
		free(arg->fork);
	return (1);
}

long long	ft_gettime()
{
	long long		ret;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	ret = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (ret);
}

void	ft_sleep(long long ms)
{
	long long	time;

	time = ft_gettime();
	while (ft_gettime() - time < ms)
		usleep(1000);
}