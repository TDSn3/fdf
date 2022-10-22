# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 14:32:32 by tda-silv          #+#    #+#              #
#    Updated: 2022/10/22 10:46:42 by tda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS = `uname -a`

CC = clang

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
	$(CC) $(CFLAGS) -Imlx_macos -c $< -o $@

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
	cd mlx_macos; make; cd ..
	$(CC) $(OBJ) -Lmlx_macos -lmlx -framework OpenGL -framework AppKit -o $(NAME)

################################################################################

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
