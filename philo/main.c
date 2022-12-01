/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:05:56 by jnoh              #+#    #+#             */
/*   Updated: 2022/11/30 14:06:41 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_arg	arg;

	if (argc != 5 && argc != 6)
		return (print_error("Error: wrong argv count\n"));
	memset(&arg, 0, sizeof(t_arg));
	if (ft_arg_init(&arg, argc, argv))
		return (print_error("Error: parsing argv\n"));
	if (ft_arg_set(&arg))
		return (print_error("Error: mutex init\n"));
	ft_philo_main(&arg);
	return (0);
}
