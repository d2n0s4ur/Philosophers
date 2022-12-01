/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:28:49 by jnoh              #+#    #+#             */
/*   Updated: 2022/12/01 11:00:44 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr(int fd, char *s)
{
	if (!s)
		return ;
	while (*(s))
		write(fd, s++, 1);
}

int	print_error(char *str)
{
	ft_putstr(2, str);
	return (1);
}

void	ft_philo_printf(t_philo *philo, char *str)
{
	long long	timestamp;

	if (ft_philo_isfinish(philo->info))
		return ;
	pthread_mutex_lock(&(philo->info->print_m));
	timestamp = ft_gettime() - philo->info->time_init;
	printf("%lld\t\t%d %s\n", timestamp, philo->pid, str);
	pthread_mutex_unlock(&(philo->info->print_m));
}
