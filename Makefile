NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./mlx -I./
SRCS = $(wildcard src/*.c) 
GETNEXTLINE = $(wildcard Get_Next_Line/*.c)
PRINTF = $(wildcard Printf/*.c)
OBJS = $(SRCS:%.c=%.o) $(GETNEXTLINE:%.c=%.o) $(PRINTF:%.c=%.o)
GCC = -Lmlx -lmlx -framework OpenGL -framework AppKit
MINILIBX = mlx/libmlx.a

all: $(NAME) $(PRINTF)

$(PRINTF):
	make -C ./Printf
$(MINILIBX):
	make -C mlx/

.c.o:
	echo $(OBJS)
	$(CC) -c $< -o $@

$(NAME): $(PRINTF) $(MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(GCC) -o $(NAME)

re: fclean all

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

.POHNY : re fclean clean all