NAME	= pipex

CC 		= gcc
CFLAGS	= -Wall -Wextra -Werror

PIPEX_SRCS =	pipex.c							\
				pipex_bonus/commands.c			\
				utils/errors.c					\
				utils/ft_split.c				\
				utils/string_manipulation.c		\
				utils/string_utils.c			\
				memory_utils/matrix.c			\
				memory_utils/processes.c		\

PIPEX_OBJS	= ${PIPEX_SRCS:.c=.o}

%.o: %.c
			$(CC) ${CFLAGS} -g -c $< -o $@ 

all: 		pipex

pipex:		${PIPEX_OBJS}
			$(CC) ${CFLAGS} -o ${NAME} ${PIPEX_OBJS}
			@(echo "\033[32mPIPEX>> Compiled\033[0m")

clean:
			rm -f *.o
			rm -f ./*/*.o
			@echo "\033[33mPIPEX>> Deleted \".o\" files\033[0m"

fclean: 	clean
			rm -rf $(NAME)
			@echo "\033[33mPIPEX>> Project cleaned\033[0m"

re: 		fclean all
			@echo "\033[0;92mPIPEX>> Project cleaned and recompiled\033[0m"

.PHONY: all clean fclean re pipex