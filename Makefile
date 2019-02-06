# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avatseba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 19:00:39 by avatseba          #+#    #+#              #
#    Updated: 2018/11/18 04:18:09 by avatseba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	wolf3d

FLAGS	=	-Wall -Werror -Wextra

DIR_H	=	./inc/

DIR_S	=	./src/

DIR_O	=	./tmp/


FT		= ./library/libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./library/libft
FT_LNK	= -L ./library/libft -l ft 

SDL_INC	= -I ./library/sdl2/2.0.8/include/SDL2/
SDL_LNK	= -L ./library/sdl2/2.0.8/lib/ -l SDL2

IMG_INC	= -I ./library/sdl2_image/2.0.4/include/SDL2/
IMG_LNK	= -L ./library/sdl2_image/2.0.4/lib/ -l SDL2_image

MIX_INC	= -I ./library/sdl2_mixer/2.0.4/include/SDL2/
MIX_LNK	= -L ./library/sdl2_mixer/2.0.4/lib/ -l SDL2_mixer

TTF_INC	= -I ./library/sdl2_ttf/2.0.14/include/SDL2/
TTF_LNK	= -L ./library/sdl2_ttf/2.0.14/lib/ -l SDL2_ttf

SRC		=	main.c \
			parser.c \
			parser_helper.c \
			error_init.c \
			error_read.c \
			error_init2.c \
			error_valid.c \
			init.c \
			init_wind.c \
			upload.c \
			core.c \
			key.c \
			menu.c \
			moving.c \
			plane_draw.c

OBJ_P	=	$(addprefix $(DIR_O), $(SRC:.c=.o))

all:	tmp $(FT_LIB) $(NAME)

tmp:
	@mkdir -p $(DIR_O)

$(DIR_O)%.o:$(DIR_S)%.c
	@gcc $(FLAGS) $(FT_INC) $(SDL_INC) $(IMG_INC) $(MIX_INC) $(TTF_INC) -I $(DIR_H) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(NAME): $(OBJ_P)
	@gcc $(OBJ_P) $(SDL_LNK) $(IMG_LNK) $(MIX_LNK) $(TTF_LNK) $(FT_LNK) -lm  -o $(NAME) -g -O0
	@echo "\033[32mAll is done!\033[0m"

clean:
	@rm -rf $(DIR_O)
	@make -C $(FT) clean
	@echo "\033[91mObject files have been deleted.\033[0m"

fclean: clean
	@rm -fr .DS*
	@rm -rf $(NAME)
	@make -C $(FT) fclean
	@echo "\033[91mAll is clear!\033[0m"

re: fclean all
