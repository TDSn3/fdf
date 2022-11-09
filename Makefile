# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 14:32:32 by tda-silv          #+#    #+#              #
#    Updated: 2022/11/09 17:42:05 by tda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = 
#CFLAGS = -Wall -Wextra -Werror

NAME = fdf

INC_DIR = include/

HEADERS = ./include/header.h \
		  ./include/struct.h \

SRC = $(addprefix ./source/, \
						   fdf.c \
						   line_put.c \
						   rotate_pixel_x.c \
						   rotate_pixel_y.c \
						   rotate_all.c \
						   my_mlx_pixel_put.c \
						   width_tab.c \
						   setup_struct.c \
						   setup_tab.c \
						   setup_hw_tab.c \
						   nb_nb_point.c \
	  ) \

OBJ = $(SRC:.c=.o)

# **************************************************************************** #
# Linux																		   #
# **************************************************************************** #

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -I mlx_linux -I libft -O3 -c $< -o $@

# **************************************************************************** #
# Mac OS																	   #
# **************************************************************************** #
#
#%.o: %.c
#	$(CC) $(CFLAGS) -I $(INC_DIR) -I mlx_macos -I libft -c $< -o $@
#
################################################################################

all: $(NAME) $(HEADERS)

# **************************************************************************** #
# Linux																		   #
# **************************************************************************** #

$(NAME): $(OBJ)
	@cd mlx_linux; make >> /dev/null 2>> /dev/null; cd ..
	@cd libft; make; cd ..
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -I$(INC_DIR) -Imlx_linux -Llibft -lft -Ilibft -lXext -lX11 -lm -lz -o $(NAME)

# **************************************************************************** #
# Mac OS																	   #
# **************************************************************************** #
#
#$(NAME): $(OBJ)
#	@cd mlx_macos; make
#	@cd libft; make
#	$(CC) $(OBJ) -Lmlx_macos -lmlx -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME)
#
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
