NAME = poly

SRC = main.cpp \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		WrongDog.cpp \

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re