NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = fdf.c error.c check_file.c check_arg.c check_num.c check_struct.c utils.c check_extension.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT = ft
INCLUDE = -I $(LIBFT_DIR)/includes -I $(MLX_DIR)
LIBRARY = -L $(LIBFT_DIR) -l $(LIBFT) -L $(MLX_DIR) -l$(MLX) -framework OpenGL -framework AppKit
MLX_DIR = minilibx_macos
MLX = mlx

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBRARY) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
