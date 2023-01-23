# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 19:20:24 by ptarrago          #+#    #+#              #
#    Updated: 2022/01/11 20:51:11 by ptarrago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

src = functions1.c functions2.c ft_printf.c

obj = ${src:.c=.o}
name = libftprintf.a
flags = -Wall -Wextra -Werror

${name}: ${obj}
		ar rcs ${name} ${obj}

%.o		: %.c ft_printf.h
		gcc $(flags) -c $< -o $@

all:	${name}

clean:
		rm -f ${obj}

fclean: clean
		rm -f ${name}

re: fclean all

.PHONY: all clean fclean re