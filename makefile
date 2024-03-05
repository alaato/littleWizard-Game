GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

SRC =  main.c error.c parse.c parse_utils.c utils.c free.c render.c movement.c end.c
OBJ = $(SRC:.c=.o)

# Link X11 and MLX
MLX_FLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
FLAGS = -Werror -Wall -Wextra
CC = cc
NAME = so_long
LIBFT 			= ./Libft/libft.a

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(SRC)
main:
	cc -g $(FLAGS) $(SRC) ${LIBFT} $(MLX_FLAGS)
