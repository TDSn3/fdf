# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 16:59:26 by tda-silv          #+#    #+#              #
#    Updated: 2022/04/02 13:16:00 by tda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ./ft_putchar.c \
	  ./ft_putchar_hexa.c \
	  ./ft_putchar_hexa_cap.c \
	  ./ft_putnbr_hexa.c \
	  ./ft_putnbr_hexa_cap.c \
	  ./ft_putnbr_int.c \
	  ./ft_putnbr_unsigned.c \
	  ./ft_putstr.c \
	  ./ft_putstr_printf.c \
	  ./ft_idconv_c.c \
	  ./ft_idconv_d_i.c \
	  ./ft_idconv_p.c \
	  ./ft_idconv_s.c \
	  ./ft_idconv_u.c \
	  ./ft_idconv_x.c \
	  ./ft_idconv_x_cap.c \
	  ./ft_convselect.c \
	  ./ft_convchr.c \
	  ./ft_datazero.c \
	  ./ft_printf.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ) ft_printf.h
	ar rc $@ ft_printf.h $^

clean:
	rm -f $(OBJ) $(OBJBNS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
