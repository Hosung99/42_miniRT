CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = minirt
SRCS = main.c execute/hit.c util/object_utils.c execute/ray.c scene.c util/vector_utils.c util/utils.c execute/constructor.c util/color_utils.c util/point_utils.c
OBJS = $(SRCS:.c=.o)
LIB_DIR = ./libft
LIBFLAG = -lft -L$(LIB_DIR)
MLX_DIR = ./minilibx/
INCLUDE = -I$(MLX_DIR)
LIB = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
MLX = -L. -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(INCLUDE)

$(NAME): $(OBJS)
	make -C minilibx
	make -C $(LIB_DIR)
	@mv ./minilibx/libmlx.dylib ./libmlx.dylib
	$(CC) -o $@ $(OBJS) $(MLX) $(LIBFLAG)

clean:
	rm -f $(OBJS)
	make -C ./libft clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f libmlx.dylib
	rm -f $(OBJS)
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
