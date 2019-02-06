# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avatseba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 18:32:00 by avatseba          #+#    #+#              #
#    Updated: 2017/11/13 18:32:22 by avatseba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a
CFLAGS  = gcc -Wall -Wextra -Werror -c
INCLUDE = libft.h
SOURCE	= ft_bzero.c ft_memalloc.c ft_strncat.c ft_memccpy.c ft_strncmp.c \
ft_memchr.c ft_strncpy.c ft_memcmp.c ft_strnequ.c ft_memcpy.c \
ft_strnew.c ft_memdel.c ft_strnstr.c ft_memmove.c ft_strrchr.c \
ft_memset.c ft_strsplit.c ft_putchar.c ft_strstr.c ft_putchar_fd.c \
ft_strsub.c ft_putendl.c ft_strtrim.c ft_putendl_fd.c ft_tolower.c \
ft_putnbr.c	ft_toupper.c ft_putnbr_fd.c ft_itoa_aslan.c ft_putstr.c \
ft_putstr_fd.c ft_slova.c ft_atoi.c ft_strcat.c ft_strchr.c \
ft_dovz.c ft_strclr.c ft_isalnum.c ft_strcmp.c ft_isalpha.c	\
ft_strcpy.c ft_isascii.c ft_strdel.c ft_isdigit.c ft_strdup.c \
ft_isprint.c ft_strequ.c ft_iswhitespaces.c	ft_striter.c ft_itoa.c \
ft_striteri.c ft_lstadd.c  ft_lstdel.c ft_strlcat.c \
ft_lstdelone.c ft_strlen.c ft_lstiter.c ft_strmap.c \
ft_lstnew.c ft_strmapi.c ft_strjoin.c ft_lstmap.c \
ft_atoi_base.c get_next_line.c

WASD = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME):
	$(CFLAGS) $(SOURCE) -I $(INCLUDE)
	ar rc $(NAME) $(WASD)
	
clean:
	rm -f $(WASD)

fclean: clean
	rm -f $(NAME)

re: fclean all
