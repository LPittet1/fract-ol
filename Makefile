NAME = fractol

CC = cc

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3

SRCS = main.c handle_error.c fractal_manager.c julia.c mandelbrot.c events.c color.c

LIBFT_PATH = libft

MLX_PATH = mlx

LIBFT = $(LIBFT_PATH)/libft.a

LIBMLX = $(MLX_PATH)/libmlx.a

OBJS = ${SRCS:.c=.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	$(CC) $(OBJS) $(LIBFT) $(LIBMLX) -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)
	@cp $(LIBFT) ./

$(LIBMLX):
	@$(MAKE) -C  $(MLX_PATH)
	@cp $(LIBMLX) ./

clean:
	rm -f $(OBJS)
	@$(MAKE) clean  -C $(LIBFT_PATH)
#@$(MAKE) clean  -C $(MLX_PATH)	

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
