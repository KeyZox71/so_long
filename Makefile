# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 11:03:22 by adjoly            #+#    #+#              #
#    Updated: 2024/01/08 13:33:38 by adjoly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

SRCS = #main.c \
		#ft_move_character.c \
		get_map.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Werror -Wall -Wextra -g

HEADER = so_long.h

MLX_OBJ = MacroLibX/libmlx.so \
			libft/libft.a

MLX_FLAGS = -lSDL2

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(MLX_FLAGS) $(OBJS) $(MLX_OBJ) -o $(NAME)

%.o: %.c
	make -C libft
	$(CC) $(FLAGS) -I $(HEADER) $< -c -o $@

all: $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean