SRC = tests.cpp\
	  Account.cpp

OBJ = $(SRC:.cpp=.o)

NAME = tests

C++ = g++

C++FLAGS = -Wall -Wextra -Werror -std=c++98

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
