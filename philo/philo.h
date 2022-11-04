/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:17:41 by jnoh              #+#    #+#             */
/*   Updated: 2022/11/04 15:21:10 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <memory.h>

typedef struct s_philo
{
	int				philo_id;
	int				lfork;
	int				rfork;
	int				eat_count;
	pthread_t		thread;
	pthread_mutex_t	*lfork_mutex;
	pthread_mutex_t	*rfork_mutex;
}	t_philo;

typedef struct	s_arg
{
	int				*fork;
	pthread_mutex_t *fork_mutex;
	t_philo			*philo;
	int				dead_cnt;
	int				number_of_philosophers;
	int				time_to_die;
	int				tiem_to_eat;
	int				tiem_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
}	t_arg;

int	print_error(char *str);

#endif