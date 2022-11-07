# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 17:19:45 by jnoh              #+#    #+#              #
#    Updated: 2022/11/07 23:13:07 by jnoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
SRCS		= philo.c print_util.c ft_atoi.c utils.c ft_philo_routine.c

OBJS		= $(SRCS:.c=.o)
NAME		= philo
RM 			= rm -f
HEADERS		= ./philo.h

all	: $(NAME)

$(NAME) : $(OBJS) $(HEADERS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) -lpthread

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS)
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

norm:
	norminette

.PHONY : all clean fclean re