# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 14:32:32 by tda-silv          #+#    #+#              #
#    Updated: 2022/10/24 19:19:11 by tda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS = `uname -a`

CC = gcc

CFLAGS = 
#CFLAGS = -Wall -Wextra -Werror

NAME = fdf

HEADERS = ./header.h \
		  ./struct.h \

SRC = ./fdf.c \

OBJ = $(SRC:.c=.o)

# **************************************************************************** #
# Linux																		   #
# **************************************************************************** #
#
#%.o: %.c
#	$(CC) $(CFLAGS) -Imlx_linux -O3 -c $< -o $@
#
# **************************************************************************** #
# Mac OS																	   #
# **************************************************************************** #

%.o: %.c
	$(CC) $(CFLAGS) -Imlx_macos -Ilibft -c $< -o $@

################################################################################

all: $(NAME) $(HEADERS)

# **************************************************************************** #
# Linux																		   #
# **************************************************************************** #
#
#$(NAME): $(OBJ)
#	cd mlx_linux; make; cd ..
#	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
#
# **************************************************************************** #
# Mac OS																	   #
# **************************************************************************** #

$(NAME): $(OBJ)
	echo $(OS)
	cd mlx_macos; make
	cd mlx_linux; make
	cd libft; make
	$(CC) $(OBJ) -Lmlx_macos -lmlx -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME)

################################################################################

clean:
	cd mlx_linux; make clean
	cd mlx_macos; make clean
	cd libft; make clean
	rm -f $(OBJ)

fclean: clean
	cd libft; make fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
