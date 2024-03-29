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
		./srcs/libft/ft_strlen.c \
		./srcs/libft/ft_atol.c \
		./srcs/libft/ft_itoa.c \
		./srcs/libft/ft_isnumeric.c \
		./srcs/init/init_t_general.c \
		./srcs/routine/routine.c \
		./srcs/routine/check_death.c \
		./srcs/routine/actions.c \
		./srcs/routine/monitoring.c \
		./srcs/utils/get_time.c \
		./srcs/utils/display_message.c \
		./srcs/utils/free_philos.c \

OBJS = ${SRCS:.c=.o}


all : $(EXEC)


$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) -pthread $^ -o $(EXEC) -I $(INCLUDES) -g

.c.o:
	$(CC) $(CFLAGS) -pthread -c $^ -o $@ -I $(INCLUDES) -g

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(EXEC)

re : fclean all

.PHONY : all clean fclean re 