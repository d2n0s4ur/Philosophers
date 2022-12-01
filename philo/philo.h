/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:17:41 by jnoh              #+#    #+#             */
/*   Updated: 2022/12/01 10:49:04 by jnoh             ###   ########.fr       */
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
	int				pid;
	int				lf;
	int				rf;
	int				cnt;
	pthread_t		tid;
	struct s_arg	*info;
	long long		last_eat;
	pthread_mutex_t	last_m;
}	t_philo;

typedef struct s_arg
{
	pthread_mutex_t	print_m;
	pthread_mutex_t	finish_m;
	pthread_mutex_t	cnt_m;
	pthread_mutex_t	*fork_m;
	t_philo			*ph;
	int				*fork;
	int				finish_eat_cnt;
	int				ph_num;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				n_must_eat;
	long long		time_init;
	int				finish;
}	t_arg;

/*
philo init
*/
int	ft_arg_init(t_arg *arg, int argc, char *argv[]);
int	ft_arg_set(t_arg *arg);

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
/*
monitor
*/
void	ft_philo_check_finish(t_arg *arg);
void	*ft_philo_check_eatcnt(void *info);
void	ft_philo_join(t_arg *arg);
int		ft_philo_isfinish(t_arg *arg);

#endif