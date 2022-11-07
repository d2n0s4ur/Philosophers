/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:28:49 by jnoh              #+#    #+#             */
/*   Updated: 2022/11/06 11:39:39 by jnoh             ###   ########.fr       */
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

void	ft_philo_print_status(t_arg *arg, t_philo *philo, char *str)
{
	printf("%lld\t\t%d %s\n", (long long)arg->time_to_die, philo->philo_id, str);
}
