NAME	= libprintf.a

SRCS	= ft_printf.c \
			pf_putstr.c \
			pf_putnbr.c \
			pf_putchar.c \
			pf_unint.c \
			pf_hex.c \
			pf_point.c \

OBJS	= $(SRCS:.c=.o)

CC		= gcc

RM		= rm -f

all:	$(NAME) clean

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
