/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:17:41 by jnoh              #+#    #+#             */
/*   Updated: 2022/11/04 18:09:32 by jnoh             ###   ########.fr       */
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
	int				*lfork;
	int				*rfork;
	int				eat_count;
	pthread_t		thread;
	pthread_mutex_t *mutex[2];
}	t_philo;

typedef struct s_arg
{
	int				*fork;
	pthread_mutex_t	*fork_mutex;
	t_philo			*philo;
	int				die_cnt;
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
}	t_arg;

/*
print utils
*/
int	print_error(char *str);
/*
utils
*/
int	ft_atoi(char *str);
int	ft_free(t_arg *arg);


#endif