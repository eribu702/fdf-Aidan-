CFLAGS	= -Wall -Werror -Wextra
CC		= gcc

NAME	= libftprintf.a
INCS	= ./includes/
SRCS	= ft_printf.c $(addprefix $(SRC_DIR)/, print_char_types.c \
		  				print_nbr_types.c print_hex_types.c print_signs.c)
OBJS	= $(SRCS:.c=.o)

SRC_DIR	= ./srcs/
LIB_DIR	= $(SRC_DIR)/libft
LIB		= $(LIB_DIR)/libft.a

AR		= ar rcs
RM		= rm -rf
TEST	= test

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(AR) $@ $(OBJS)

$(LIB):
	make -C $(LIB_DIR)
	cp $@ $(NAME)

$(TEST): $(NAME) $(LIB)
	$(CC) $(CFLAGS) main.c $(NAME) -o $@
	./test

clean:
	$(RM) $(OBJS)
	$(RM) $(TEST)
	make -C $(LIB_DIR) fclean

fclean: clean
	$(RM) $(NAME)

re: clean fclean all test
