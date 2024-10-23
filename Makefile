NAME = fract

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = main.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
		rm -f $(OBJS)	

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
