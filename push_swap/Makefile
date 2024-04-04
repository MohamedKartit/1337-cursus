# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkartit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 20:05:51 by mkartit           #+#    #+#              #
#    Updated: 2024/03/14 20:05:53 by mkartit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC= push_swap.c ft_split.c ft_parsing.c ft_conv_nums.c ft_checkers.c ft_printing.c ft_utils.c ft_commands.c ft_commands_2.c push_swap_utils.c push_swap_utils_2.c

SRC_BONUS= $(SRC) checker_bonus.c get_next_line.c get_next_line_utils.c
OBJ_BONUS= $(SRC_BONUS:.c=.o)

OBJ= $(SRC:.c=.o)
NAME= push_swap
CC= cc
CFLAGS= -Wall -Wextra -Werror

NAME_BONUS= checker

%.o: %.c
	$(CC) $(CFLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJ) main.c
	$(CC) $(CFLAGS) $^ -o $(NAME) 

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	rm -rf main.o

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $^ -o $(NAME_BONUS)

re: fclean all

.PHONY: all NAME clean fclean re
