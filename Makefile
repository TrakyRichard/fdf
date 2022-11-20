NAME = fdf
SRCS = ./srcs/fdf.c ./srcs/utils/error.c ./srcs/utils/init.c ./srcs/utils/ops.c \
		./srcs/utils/parser.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		./srcs/utils/io.c ./srcs/utils/util.c ./srcs/utils/free.c ./srcs/utils/display.c ./srcs/utils/draw.c \
		./srcs/utils/close.c ./srcs/utils/key.c ./srcs/utils/draw_utils.c
LIBFT = libft.a
LIBFT_DIR = libft/
GNL_DIR = get_next_line/
MLX_DIR = minilibx_macos
MLX_FLAGS = -framework OpenGL -framework AppKit
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
INCS = -I ./includes

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@make -C $(GNL_DIR)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -I./includes

$(MLX):
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft $(MLX_FLAGS)

clean:
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean
	@make -C $(GNL_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(GNL_DIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
