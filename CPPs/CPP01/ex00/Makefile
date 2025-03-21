SRC = main.cpp\
	  Zombie.cpp\
	  newZombie.cpp\
	  randomChump.cpp

OBJ=${SRC:.cpp=.o}

CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98
NAME=test

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