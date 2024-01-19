# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 11:03:22 by adjoly            #+#    #+#              #
#    Updated: 2024/01/19 13:41:58 by adjoly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

SRCS = main.c \
		get_map.c \
		ft_move_character.c \
		print_map.c \
		ft_check_map_error.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Werror -Wall -Wextra -g

HEADERS = so_long.h

LIB = MacroLibX/libmlx.so \
			libft/libft.a \
			get_next_line/get_next_line.a \
			printf/libftprintf.a

MLX_FLAGS = -lSDL2

$(NAME): $(OBJS)
	make -C libft
	make -C get_next_line
	make -C printf
	$(CC) $(FLAGS) $(MLX_FLAGS) $(OBJS) $(LIB) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I $(HEADERS) $< -c -o $@

all: $(NAME)

clean:
	make -C libft clean
	make -C get_next_line clean
	make -C printf clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	make -C get_next_line fclean
	make -C printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean