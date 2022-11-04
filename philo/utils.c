/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:08:53 by jnoh              #+#    #+#             */
/*   Updated: 2022/11/04 18:09:09 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_free(t_arg *arg)
{
	if (arg->philo)
		free(arg->philo);
	if (arg->fork)
		free(arg->fork);
	if (arg->fork_mutex)
		free(arg->fork_mutex);
	return (1);
}
