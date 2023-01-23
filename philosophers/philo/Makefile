# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 13:58:19 by ptarrago          #+#    #+#              #
#    Updated: 2022/07/02 21:54:18 by ptarrago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c check_func.c other_func.c philo_staff.c time_func.c ft_init.c
OBJ = ${SRC:.c=.o}
NAME = philo
FLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread
HEAD = philo.h

${NAME}: ${HEAD} ${OBJ} Makefile
	gcc $(FLAGS) ${OBJ} -I $(HEAD) -o ${NAME}

%.o   : %.c ${HEAD}
	gcc $(FLAGS) -c $< -o $@

all:
		make ${NAME}

clean:

		rm -rf ${OBJ}
		
fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
