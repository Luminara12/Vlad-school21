# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 17:58:18 by ptarrago          #+#    #+#              #
#    Updated: 2022/07/06 15:11:32 by ptarrago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=		push_swap

NAME_B		=		checker

HEAD 		=		push_swap.h

HEAD_B		=		push_swap_bonus.h

SRC 		= 		alg_FF.c alg_list_prepare.c alg_minisort.c alg_voila.c func_libht2.c func_libth.c \
					func_lst1.c func_lst2.c func_minimax.c func_push.c func_revrotate.c func_rotate1.c func_swap.c push_swap.c quicksort.c	

SRC_B 		= 		b1.c b2.c b3.c b4.c b5.c b6.c b7.c b8.c checker.c

OBJ 		=		$(SRC:%.c=%.o)

OBJ_B		=		$(SRC_B:%.c=%.o)

D 			=		$(SRC:%.c=%.d)

D_B 		=		$(SRC_B:%.c=%.d)

CFLAGS 		= 		-Wall -Werror -Wextra

CC 			= 		gcc

RM 			= 		rm -f

all 		: 		
					make $(NAME)


$(NAME) 	: 		$(OBJ) Makefile
					$(CC) $(CFLAGS) $(OBJ) -o $@

%.o 		: 		%.c
					$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@

include 			$(wildcard $(D) $(D_B))

bonus		:		
					@make OBJ="$(OBJ_B)" HEAD="$(HEAD_B)" NAME="$(NAME_B)" all

clean		:
					@$(RM) $(OBJ) $(D) $(OBJ_B) $(D_B) 

fclean		: 		clean
					@$(RM) $(NAME) $(NAME_B)

re			: 		fclean all

.PHONY		: 		all clean fclean re bonus