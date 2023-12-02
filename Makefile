CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = minirt
SRCS = hit.c main.c object_utils.c ray.c scene.c vector_utils.c utils.c constructor.c color_utils.c point_utils.c
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

$(NAME): libft $(OBJS) $(MLX) print.h scene.h trace.h utils.h structures.h
	$(CC) -o $@ $(OBJS) $(INCLUDE) $(LIB) $(LIBFT)

$(MLX) :
	make -C $(MLX_DIR)

libft:
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft
