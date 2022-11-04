/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:18:58 by jnoh              #+#    #+#             */
/*   Updated: 2022/11/04 18:14:46 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_input(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			while (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			if (argv[i][j])
				return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_arg_init(t_arg *arg, int argc, char *argv[])
{
	if (ft_check_input(argc, argv))
		return (1);
	arg->philo_num = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		arg->time_must_eat = ft_atoi(argv[5]);
	else
		arg->time_must_eat = -1;
	arg->philo = malloc(arg->philo_num * sizeof(t_philo));
	arg->fork = malloc(arg->philo_num * sizeof(int));
	arg->fork_mutex = malloc(arg->philo_num * sizeof(pthread_mutex_t));
	if (!(arg->philo) || !(arg->fork) || !(arg->fork_mutex))
		return (ft_free(arg));
	memset(arg->philo, 0, arg->philo_num * sizeof(t_philo));
	memset(arg->fork, 0, arg->philo_num * sizeof(int));
	return (0);
}

static int	ft_arg_set(t_arg *arg)
{
	int	i;

	i = 0;
	// mutex init
	while (i < arg->philo_num)
	{
		arg->philo[i].philo_id = i + 1;
		arg->philo[i].lfork = &(arg->fork[i]);
		arg->philo[i].rfork = &(arg->fork[i + 1]);
		arg->philo[i].mutex[0] = &(arg->fork_mutex[i]);
		arg->philo[i].mutex[1] = &(arg->fork_mutex[i + 1]);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_arg	arg;
	int		status;

	if (argc != 5 && argc != 6)
		return (print_error("Error: wrong argv count\n"));
	memset(&arg, 0, sizeof(t_arg));
	status = ft_arg_init(&arg, argc, argv);
	if (status)
		return (print_error("Error: parsing argv\n"));
	ft_arg_set(&arg);
	return (0);
}
