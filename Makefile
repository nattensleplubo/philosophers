CC		= gcc
SAN		= -fsanitize=address
CFLAGS	= -Wall -Wextra -Werror ##$(SAN)
EXEC	= philo

INCLUDES		= ./includes/
# INCLUDESRL		= /usr/local/opt/readline/include/
# INCLUDESLIBFT	= ./libft/

SRCS = ./main.c \
		./srcs/check/check_arguments.c \
		./srcs/error_handling/print_errors.c \

OBJS = ${SRCS:.c=.o}


all : $(EXEC)


$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(EXEC) -I $(INCLUDES) -g

.c.o:
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(INCLUDES) -g

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(EXEC)

re : fclean all

.PHONY : all clean fclean re 