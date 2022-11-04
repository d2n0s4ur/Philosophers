/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:18:58 by jnoh              #+#    #+#             */
/*   Updated: 2022/11/03 17:41:42 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_arg_init(t_arg *arg, int argc, char argv[])
{
	
}

int	main(int argc, char argv[])
{
	t_arg	arg;

	if (argc != 5 && argc != 6)
		return (print_error("wrong argv count\n"));
	memset(&arg, 0, sizeof(t_arg));
	ft_arg_init(&arg, argc, argv);
	
	return (0);
}