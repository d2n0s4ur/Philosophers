/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:17:41 by jnoh              #+#    #+#             */
/*   Updated: 2022/11/10 20:58:50 by jnoh             ###   ########.fr       */
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
	pthread_mutex_t	lfork;
	pthread_mutex_t	rfork;
	int				eat_count;
	int				died;
	pthread_t		thread;
	struct s_arg	*info;
	long long		last_eat;
}	t_philo;

typedef struct s_arg
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	t_philo			*philo;
	int				die_cnt;
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
	long long		time_init;
	int				finish;
}	t_arg;

/*
print utils
*/
int		print_error(char *str);
void	ft_philo_printf(t_philo *philo, char *str);
/*
utils
*/
int			ft_atoi(char *str);
int			ft_free(t_arg *arg);
long long	ft_gettime();
void		ft_sleep(long long ms);
/*
routine
*/
int	ft_philo_main(t_arg *arg);

#endif