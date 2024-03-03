CFLAGS	= -Wall -Werror -Wextra
CC		= gcc

NAME	= libft.a
BONUS	= bonus
ADDED	= add

SRCS	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_strlcpy.c ft_memset.c ft_bzero.c ft_memcpy.c \
			ft_memmove.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strdup.c \
			ft_atoi.c ft_calloc.c ft_strrchr.c ft_memchr.c ft_memcmp.c \
			ft_strchr.c ft_strncmp.c ft_strnstr.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_itoa.c ft_split.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c
B_SRC	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
ADD_SRC	=	ft_strcmp.c strchr_flag.c ft_strnjoin.c ft_free.c trim_component.c \
			hex_atoi.c ft_strndup.c float_to_array.c long_atoi.c \

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(B_SRC:.c=.o)
ADDED_OBJS	= $(ADD_SRC:.c=.o)

all: $(NAME) $(BONUS) $(ADDED)

.c.o:
	${CC} $(CFLAGS) -g -I . -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(BONUS): $(OBJS) $(BONUS_OBJS)
	ar rc $(NAME) $(OBJS) $(BONUS_OBJS)
	ranlib $(NAME)

$(ADDED): $(OBJS) $(BONUS_OBJS) $(ADDED_OBJS)
	ar rc $(NAME) $(OBJS) $(BONUS_OBJS) $(ADDED_OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(ADDED_OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all
