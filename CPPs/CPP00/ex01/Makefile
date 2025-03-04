
SRC = main.cpp\
	  Contact.cpp\
	  PhoneBook.cpp\
	  utils.cpp

OBJ = $(SRC:.cpp=.o)

NAME = phonebook

C++ = g++
C++FLAGS = -Wall -Wextra -Werror -g3 -std=c++98

%.o: %.cpp
	$(C++) $(C++FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(C++FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)
