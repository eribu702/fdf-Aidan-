# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 17:46:51 by aroberts          #+#    #+#              #
#    Updated: 2024/02/20 14:59:11 by aroberts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./srcs/ft_isalnum.c \
		./srcs/ft_isprint.c \
		./srcs/ft_memcmp.c \
		./srcs/ft_putchar_fd.c \
		./srcs/ft_split.c \
		./srcs/ft_strlcat.c \
		./srcs/ft_strncmp.c \
		./srcs/ft_substr.c \
		./srcs/ft_atoi.c \
		./srcs/ft_isalpha.c \
		./srcs/ft_itoa.c \
		./srcs/ft_memcpy.c \
		./srcs/ft_putendl_fd.c \
		./srcs/ft_strchr.c \
		./srcs/ft_strlcpy.c \
		./srcs/ft_strnstr.c \
		./srcs/ft_tolower.c \
		./srcs/ft_bzero.c \
		./srcs/ft_isascii.c \
		./srcs/ft_memmove.c \
		./srcs/ft_putnbr_fd.c \
		./srcs/ft_strdup.c \
		./srcs/ft_strlen.c \
		./srcs/ft_strrchr.c \
		./srcs/ft_toupper.c \
		./srcs/ft_calloc.c \
		./srcs/ft_isdigit.c \
		./srcs/ft_memchr.c \
		./srcs/ft_memset.c \
		./srcs/ft_putstr_fd.c \
		./srcs/ft_strjoin.c \
		./srcs/ft_strmapi.c \
		./srcs/ft_strtrim.c \
		./srcs/ft_striteri.c \
		./srcs/ft_free/ft_free.c \
		./srcs/ft_strnjoin/ft_strnjoin.c \
		./srcs/ft_strndup/ft_strndup.c \
		./srcs/ft_strchr_flag/ft_strchr_flag.c \
		./srcs/ft_strcmp/ft_strcmp.c \
		./srcs/ft_hex_atoi/ft_hex_atoi.c \
		./srcs/ft_trim_component/ft_trim_component.c \

#PRINTF = ./printf/ft_printf.c \
		./printf/pf_putchar.c \
		./printf/pf_hex.c \
		./printf/pf_putnbr.c \
		./printf/pf_unint.c \
		./printf/pf_point.c \
		./printf/pf_putstr.c \

#GETNEXTLINE = ./gnl/get_next_line.c \


CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
OBJS = $(SRCS:.c=.o)
NAME = libft.a

all: $(NAME) clean

$(NAME):	$(OBJS)
	
	ar rcs $(NAME) $(OBJS)

clean: 
	-rm -f $(OBJS)
	-rm -f *.o

fclean: clean
	-rm -f $(OBJS)
	-rm -f $(NAME)

lib: all
	-rm -f $(OBJS)

re: fclean lib

.PHONY: all clean fclean re
