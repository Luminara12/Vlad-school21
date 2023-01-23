SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRCS_SERVER = server.c functions.c
SRCS_CLIENT = client.c functions.c
SRCS_SERVER_BONUS = server_bonus.c functions_bonus.c
SRCS_CLIENT_BONUS = client_bonus.c functions_bonus.c

HEADER = minitalk.h

HEADER_BONUS = minitalk.h

SERVER_OBJS = ${SRCS_SERVER:%.c=%.o}
CLIENT_OBJS = ${SRCS_CLIENT:%.c=%.o}
SERVER_OBJS_BONUS = ${SRCS_SERVER_BONUS:%.c=%.o}
CLIENT_OBJS_BONUS = ${SRCS_CLIENT_BONUS:%.c=%.o}

CFLAGS = -Wall -Wextra -Werror

all:	${SERVER} ${CLIENT}

bonus:
		@make SERVER="${SERVER_BONUS}" \
		CLIENT="${CLIENT_BONUS}" \
		SERVER_OBJS="${SERVER_OBJS_BONUS}" \
		CLIENT_OBJS="${CLIENT_OBJS_BONUS}" \
		HEADER="${HEADER_BONUS}" all

${SERVER}:	${SERVER_OBJS} ${HEADER}
	cc ${SERVER_OBJS} -o ${SERVER}

${CLIENT}:	${CLIENT_OBJS} ${HEADER}
	cc ${CLIENT_OBJS} -o ${CLIENT}

clean:
	rm -f ${SERVER_OBJS} ${CLIENT_OBJS} ${SERVER_OBJS_BONUS} ${CLIENT_OBJS_BONUS}

fclean: clean
	rm -f ${SERVER} ${CLIENT} ${SERVER_BONUS} ${CLIENT_BONUS}

re:	fclean all

bre: fclean bonus

.PHONY: all clean fclean re bonus bre