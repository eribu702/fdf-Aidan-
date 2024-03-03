NAME		= fdf
SRC_PATH	= srcs
HDR_PATH	= includes
MLX_PATH	= mlx/
OBJ_PATH	= objects
SHARED_PATH	= $(OBJ_PATH)/shared

LIB_PATH	= $(addprefix $(SRC_PATH)/shared/, ft_printf)
SRC_SHARED	= $(addprefix shared/, init.c utils.c read_map.c map.c stack.c \
			debug.c render.c colour.c destroy.c hooks.c projection.c \
			point.c events.c math.c rotate.c menu.c )

SRC_FILES	= fdf.c $(SRC_SHARED)
LIB_FILE	= libftprintf.a
MLX_FILE	= libmlx.a

SRC_NAME	= $(SRC_FILES:.c=.o)
SRC_OBJ		= $(addprefix $(OBJ_PATH)/, $(SRC_NAME))
SRCS		= $(addprefix $(SRC_PATH)/, $(SRC_FILES))

LIB_PRINTF	= $(addprefix $(SHARED_PATH)/, $(LIB_FILE))
MLX_LIB		= $(addprefix $(SHARED_PATH)/, $(MLX_FILE))
INC			= -I $(HDR_PATH)
CC			= gcc -Wall -Werror -Wextra -g
FLAGS		= -lm

UNAME := $(shell uname -s)
ifeq ($(UNAME),Linux)
	MLX_PATH := mlx/LINUX
	FLAGS += -lX11 -lXext
	CC += -D KEYS=1
else ifeq ($(UNAME),Darwin)
	MLX_PATH := mlx/MAC
	FLAGS += -framework OpenGL -framework AppKit
	CC += -D KEYS=2
endif

all: $(NAME)

$(NAME): $(LIB_PRINTF) $(MLX_LIB) $(SRC_OBJ)
	@echo "Compiling FDF..."
	@rm -rf $(NAME)
	@$(CC) $(INC) $(SRC_OBJ) $(LIB_PRINTF) $(MLX_LIB) -o $@ $(FLAGS)
	@echo "Done!"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HDR) $(LIB_PRINTF)
	@echo "Building Objects..."
	@$(CC) $(INC) -c $< -o $@

$(LIB_PRINTF):
	@echo "Compiling Libraries..."
	@make -s -C $(LIB_PATH) $(LIB_FILE)
	@mkdir -p $(OBJ_PATH) $(SHARED_PATH)
	@cp $(LIB_PATH)/$(LIB_FILE) $(LIB_PRINTF)

$(MLX_LIB):
	@echo "Compiling MLX Library..."
	@make -s -C $(MLX_PATH) all
	@cp $(MLX_PATH)/$(MLX_FILE) $(MLX_LIB)
	@cp $(MLX_PATH)/mlx.h $(HDR_PATH)/mlx.h

clean:
	@make -s -C $(LIB_PATH) fclean
	@make -s -C $(MLX_PATH) clean
	@rm -rf $(HDR_PATH)/mlx.h
	@rm -rf $(OBJ_PATH)
	@echo "OBJECTS REMOVED!"

fclean: clean
	@rm -rf $(NAME)
	@echo "FDF Executable REMOVED!"

norm:
	norminette srcs/ includes/

re: clean fclean norm all
