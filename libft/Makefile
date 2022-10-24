# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 16:59:26 by tda-silv          #+#    #+#              #
#    Updated: 2022/10/24 21:05:28 by tda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

HEADERS = ./libft.h \
		  ./get_next_line/get_next_line_bonus.h \

SRC = ./ft_isalpha.c \
	  ./ft_isdigit.c \
	  ./ft_isalnum.c \
	  ./ft_isascii.c \
	  ./ft_isprint.c \
	  ./ft_strlen.c \
	  ./ft_memset.c \
	  ./ft_bzero.c \
	  ./ft_memcpy.c \
	  ./ft_memmove.c \
	  ./ft_strlcpy.c \
	  ./ft_strlcat.c \
	  ./ft_toupper.c \
	  ./ft_tolower.c \
	  ./ft_strchr.c \
	  ./ft_strrchr.c \
	  ./ft_strncmp.c \
	  ./ft_memchr.c \
	  ./ft_memcmp.c \
	  ./ft_strnstr.c \
	  ./ft_atoi.c \
	  ./ft_calloc.c \
	  ./ft_strdup.c \
	  ./ft_substr.c \
	  ./ft_strjoin.c \
	  ./ft_strtrim.c \
	  ./ft_split.c \
	  ./ft_itoa.c \
	  ./ft_strmapi.c \
	  ./ft_striteri.c \
	  ./ft_putchar_fd.c \
	  ./ft_putstr_fd.c \
	  ./ft_putendl_fd.c \
	  ./ft_putnbr_fd.c \
	  ./get_next_line/get_next_line_bonus.c \
	  ./my_strjoin_free.c \
	  $(addprefix ./t_dl/, \
	  	dl_add_back.c \
		dl_clear_one.c \
		dl_clear.c \
		dl_find_content.c \
		dl_last.c \
		dl_new.c \
		dl_size.c \
	  ) \
	  $(addprefix ./t_li/, \
	  	li_add_back.c \
		li_clear_one.c \
		li_clear.c \
		li_find_content.c \
		li_last.c \
		li_new.c \
		li_size.c \
	  ) \

BNS = ./ft_lstnew.c \
	  ./ft_lstadd_front.c \
	  ./ft_lstsize.c \
	  ./ft_lstlast.c \
	  ./ft_lstadd_back.c \
	  ./ft_lstdelone.c \
	  ./ft_lstclear.c \
	  ./ft_lstiter.c \
	  ./ft_lstmap.c \

OBJ = $(SRC:.c=.o)

OBJBNS = $(BNS:.c=.o)

all: $(NAME) $(HEADERS)

%.o : %.c
	$(CC) $(CFLAGS) -Ift_printf -o $@ -c $<

$(NAME): $(OBJ)
	cd ./ft_printf; make
	ar rc $@ libft.h $^

bonus: $(OBJ) $(OBJBNS)
	ar rc -Lft_printf -lftprintf $(NAME) libft.h $^

clean:
	cd ./ft_printf; make clean
	rm -f $(OBJ) $(OBJBNS)

fclean: clean
	cd ./ft_printf; make fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
