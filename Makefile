NAME = fractol

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = main.c handle_error.c fractal_manager.c julia.c mandelbrot.c\
		 events.c color.c utils.c tricorn.c init_and_exit.c

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

$(LIBMLX):
	@$(MAKE) -C  $(MLX_PATH)

clean:
	rm -f $(OBJS)
	@$(MAKE) clean -C $(LIBFT_PATH)
#@$(MAKE) clean  -C $(MLX_PATH)	

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
