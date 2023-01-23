# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 12:53:23 by ptarrago          #+#    #+#              #
#    Updated: 2022/06/11 13:04:03 by ptarrago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

src = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
ft_memchr.c ft_memcmp.c ft_strchr.c ft_memcpy.c ft_memmove.c ft_strrchr.c ft_memset.c ft_strlcat.c\
ft_strlcpy.c ft_strlen.c ft_strlcat.c ft_strncmp.c ft_strncmp.c ft_tolower.c ft_toupper.c\
ft_calloc.c ft_strnstr.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c\
ft_split.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c get_next_line.c ft_hex_atoi.c

obj = ${src:.c=.o}
name = libft.a
flags = -Wall -Wextra -Werror
head = libft.h
${name}: ${head} ${obj}
		ar rcs ${name} ${obj}

%.o		: %.c ${head}
		gcc $(flags) -c $< -o $@

all:	${name}

clean:
		rm -f ${obj}

fclean: clean
		rm -f ${name}

re: fclean all

.PHONY: all co clean fclean re