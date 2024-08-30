SRCS			=	src/routine.c src/threads.c src/ph_utils.c src/main.c src/thread_utils.c src/death.c src/init.c src/ph_ato.c src/clean.c src/eat.c src/take_fork.c src/drop_forks.c
OBJS			= $(SRCS:.c=.o)


CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g -fsanitize=thread

NAME			= philo

%.o:			%.c
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)
$(NAME):
				$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all 


.PHONY:			all clean fclean re
