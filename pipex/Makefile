# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkartit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 15:24:23 by mkartit           #+#    #+#              #
#    Updated: 2024/02/19 18:18:37 by mkartit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = pipex.c helper.c helper2.c utils.c 
SRC_B = pipex_bonus.c get_next_line.c get_next_line_utils.c helper.c helper2.c utils_bonus1.c utils_bonus2.c
OBJ = ${SRC:.c=.o}
OBJ_B = ${SRC_B:.c=.o}
NAME =pipex
NAME_B =pipex_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror 


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(NAME_B)
$(NAME_B): $(OBJ_B)
	$(CC) $(CFLAGS) $(OBJ_B) -o $(NAME_B)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_B)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_B)

re: fclean all

.PHONY: all clean fclean re
