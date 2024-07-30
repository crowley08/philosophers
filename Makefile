SRCS			=	src/routine.c src/threads.c
OBJS			= $(SRCS:.c=.o)


CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g

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