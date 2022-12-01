/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:18:58 by jnoh              #+#    #+#             */
/*   Updated: 2022/11/30 16:56:35 by jnoh             ###   ########.fr       */
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
			if (argv[i][j] == '+')
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

int	ft_arg_init(t_arg *arg, int argc, char *argv[])
{
	if (ft_check_input(argc, argv))
		return (1);
	arg->ph_num = ft_atoi(argv[1]);
	arg->t_to_die = ft_atoi(argv[2]);
	arg->t_to_eat = ft_atoi(argv[3]);
	arg->t_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		arg->n_must_eat = ft_atoi(argv[5]);
	else
		arg->n_must_eat = 0;
	if (arg->ph_num < 1 || arg->t_to_die < 1 || arg->t_to_eat < 1 || \
		arg->t_to_sleep < 1 || (arg->n_must_eat < 0))
		return (1);
	arg->ph = malloc(arg->ph_num * sizeof(t_philo));
	arg->fork = malloc(arg->ph_num * sizeof(int));
	arg->fork_m = malloc(arg->ph_num * sizeof(pthread_mutex_t));
	if (!(arg->ph) || !(arg->fork) || !(arg->fork_m))
		return (ft_free(arg));
	memset(arg->ph, 0, arg->ph_num * sizeof(t_philo));
	memset(arg->fork, 0, arg->ph_num * sizeof(int));
	return (0);
}

int	ft_arg_set(t_arg *arg)
{
	int	i;

	if (pthread_mutex_init(&(arg->print_m), NULL))
		return (1);
	if (pthread_mutex_init(&(arg->finish_m), NULL))
		return (1);
	if (pthread_mutex_init(&(arg->cnt_m), NULL))
		return (1);
	i = 0;
	arg->time_init = ft_gettime();
	while (i < arg->ph_num)
	{
		if (pthread_mutex_init(&(arg->fork_m[i]), NULL))
			return (1);
		if (pthread_mutex_init(&(arg->ph[i].last_m), NULL))
			return (1);
		arg->ph[i].pid = i + 1;
		arg->ph[i].info = arg;
		arg->ph[i].lf = i;
		arg->ph[i].rf = (i + 1) % arg->ph_num;
		arg->ph[i].last_eat = arg->time_init;
		i++;
	}
	return (0);
}
