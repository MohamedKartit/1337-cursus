src= main.cpp \
	 Bureaucrat.cpp \
	 AForm.cpp \
	 ShrubberyCreationForm.cpp \
	 RobotomyRequestForm.cpp \
	 PresidentialPardonForm.cpp\
	 Intern.cpp

OBJ=$(src:.cpp=.o)

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Bureaucrat 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)