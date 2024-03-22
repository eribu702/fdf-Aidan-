NAME = fdf
RM = @rm -rf
SRC_PATH = srcs
MLX_PATH = mlx
PRI_PATH = printf
LIB_PATH = libft
HDR_PATH = includes
MCLEAN = @make clean -s -C
MFCLEAN = @make fclean -s -C

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

all: $(NAME)

$(NAME): $(MLX_LIBRARY)
	@make -s -C ./libft
	@make -s -C ./printf
	@gcc -Wall -Werror -Wextra -I. -I$(MLX_PATH) -L$(MLX_PATH) -lmlx -L$(LIB_PATH) -lft -L$(PRI_PATH) -lprintf  $(FLAGS) $(SRCS) -o $@

$(MLX_LIBRARY):
	@make -s -C $(MLX_PATH)
	@echo "READY"

clean:
	$(MCLEAN) $(MLX_PATH)
	$(MCLEAN) $(PRI_PATH)
	$(MCLEAN) $(LIB_PATH)
	@echo "CLEANED"

fclean: clean
	$(MFCLEAN) $(PRI_PATH)
	$(MFCLEAN) $(LIB_PATH)
	$(RM) $(NAME)
	@echo "FINISHED"
	
norm:
	@echo "NORM CHECK:"
	norminette srcs/ includes/|| true

run: all clean
	$(MFCLEAN) $(PRI_PATH)
	$(MFCLEAN) $(LIB_PATH)
	@echo "GO TIME"

re:
	@echo "RECYCLING"
	@make fclean
	@make all

.PHONY: all clean fclean norm re run