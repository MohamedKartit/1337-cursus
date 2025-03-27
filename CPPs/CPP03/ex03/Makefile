SRC = main.cpp\
	  ClapTrap.cpp\
	  ScavTrap.cpp\
	  FragTrap.cpp\
	  DiamondTrap.cpp

OBJ=${SRC:.cpp=.o}

CC=g++
CFLAGS=-Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98
NAME=ClapTrap

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)