# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roddavid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/23 11:27:10 by roddavid          #+#    #+#              #
#    Updated: 2018/02/15 19:12:51 by roddavid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=			fdf

#==============================================================================#
#------------------------------------------------------------------------------#
#                                  FILES                                       #

SRC				:=			Srcs/main.c						\
							Srcs/ft_parser.c				\
							Srcs/ft_projection.c			\
							Srcs/ft_bresenham.c				\
							Srcs/mlx_pixel_put_to_image.c	\
							Srcs/ft_hook.c					\

OBJ				:=			$(SRC:.c=.o)

L_FT			:=			./Libft/

LIB				:=			./Libft/libft.a

LIBX_FT			:=			./minilibx_macos/

LIBX			:=			./minilibx_macos/libmlx.a
#==============================================================================#
#------------------------------------------------------------------------------#
#                            COMPILER & FLAGS                                  #

CFLAGS			:=			-Wall -Wextra -Werror -g3
MLXFLAGS		:=			-framework OpenGL -framework AppKit

#------------------------------------------------------------------------------#
#                                 RULES                                        #

all:					$(NAME)

$(NAME):				$(LIBX) $(LIB) $(OBJ)
	$(CC) $(OBJ) -I libft.h -I fdf.h $(MLXFLAGS) $(CFLAGS) ./Libft/libft.a \
		./minilibx_macos/libmlx.a -o $(NAME)
	@printf '\033[33m[ ▴ ] %s\n\033[0m' "Compilation of $(NAME) is done ---"

$(LIB):
	@make -C $(L_FT)

$(LIBX):
	make -C $(LIBX_FT)

clean:
	@make -C $(L_FT) clean
	@make -C $(LIBX_FT) clean
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: 				clean
	rm -rf $(NAME)
	@make -C $(L_FT) fclean --no-print-directory
	@printf '\033[33m[ ▴ ] %s\n\033[0m' "Fclean of $(NAME) is done ---"¬

re:						fclean all

.PHONY: all clean fclean re
