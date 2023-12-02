CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = minirt
SRCS = main.c execute/hit.c util/object_utils.c execute/ray.c scene.c util/vector_utils.c util/utils.c execute/constructor.c util/color_utils.c util/point_utils.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT = -L$(LIBFT_DIR) -lft
MLX_DIR = ./minilibx/
MLX = $(MLX_DIR)libmlx.a
INCLUDE = -I$(MLX_DIR)
LIB = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(INCLUDE)

$(NAME): libft $(OBJS) $(MLX) util/utils.h structures.h
	$(CC) -o $@ $(OBJS) $(INCLUDE) $(LIB) $(LIBFT)

$(MLX) :
	make -C $(MLX_DIR)

libft:
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C libft clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft
