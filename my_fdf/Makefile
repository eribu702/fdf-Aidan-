NAME = fdf
RM = rm -rf
SRC_PATH = srcs
MLX_PATH = mlx
PRI_PATH = printf
LIB_PATH = libft
HDR_PATH = includes
MCLEAN = make clean -C
MFCLEAN = make fclean -C

MLX_LIBRARY = $(MLX_PATH)/libmlx.a

SRCS:=$(addprefix $(SRC_PATH)/, $(addsuffix .c, \
	fdf \
	render \
	colours \
	hooks \
	runner \
	init \
	destroy \
	utils \
	stack \
))

FLAGS += -framework OpenGL -framework AppKit

all: norm $(NAME)

$(NAME): $(MLX_LIBRARY)
	make -C ./libft
	make -C ./printf
	gcc -Wall -Werror -Wextra -I. -I$(MLX_PATH) -L$(MLX_PATH) -lmlx -L$(LIB_PATH) -lft -L$(PRI_PATH) -lprintf  $(FLAGS) $(SRCS) -o $@

$(MLX_LIBRARY):
	make  -C $(MLX_PATH)

clean:
	$(MCLEAN) $(MLX_PATH)
	$(MCLEAN) $(PRI_PATH)
	$(MCLEAN) $(LIB_PATH)

fclean: clean
	$(MFCLEAN) $(PRI_PATH)
	$(MFCLEAN) $(LIB_PATH)
	$(RM) $(NAME)
	
norm:
	norminette srcs/ includes/|| true

re: fclean all

.PHONY: all clean fclean norm re