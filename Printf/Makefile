NAME = libftprintf.a

SRCS = ft_printf.c \
		ft_printf_utils.c

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

$(NAME):
		gcc $(FLAGS) -c $(SRCS)
		ar rc $(NAME) $(OBJS)


all: $(NAME)

clean:
		rm -rf $(OBJS)

fclean:
		rm -rf $(NAME) $(OBJS)

re: 	clean fclean