NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lm
LIBFT = libft/libft.a
FT_PRINTF = printf/libftprintf.a

SRCS = fdf.c \
       drawing.c \
       events.c \
       projection.c \
       file_read.c \
       get_next_line/get_next_line.c \
       get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) minilibx-linux/libmlx.a
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS) -Lprintf -lftprintf -Llibft -lft

minilibx-linux/libmlx.a:
	$(MAKE) -C minilibx-linux

$(LIBFT):
	$(MAKE) -C libft

$(FT_PRINTF):
	$(MAKE) -C printf

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean
	$(MAKE) -C printf clean
	$(MAKE) -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C printf fclean
	rm -f minilibx-linux/libmlx.a

re: fclean all
