# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 12:53:37 by ptarrago          #+#    #+#              #
#    Updated: 2022/06/11 13:01:58 by ptarrago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = matrix_read.c bresenham_alg.c draw_map.c main.c
OBJ = ${SRC:.c=.o}
NAME = fdf
FLAGS = -Wall -Wextra -Werror
HEAD = fdf.h
MLX_DIR = ./minilibx_macos
MLX_FLAGS = -L ${MLX_DIR} -lmlx -framework OpenGL -framework AppKit
${NAME}: relinc
relinc	:
		make -C ./libft
		make -C ${MLX_DIR}
		make ${OBJ}
		gcc ${FLAGS} ${OBJ} -I ${HEAD} -L ./libft -lft -lm ${MLX_FLAGS} -o ${NAME}

%.o   : %.c ${HEAD}
		gcc ${FLAGS} -I ${MLX_DIR} -c $< -o $@

all:
		make ${NAME}

clean:
		make clean -C ./libft
		make clean -C ${MLX_DIR}
		rm -rf ${OBJ}
		
fclean: clean
		make fclean -C ./libft
		make clean -C ${MLX_DIR}
		rm -f ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re relinc