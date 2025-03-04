#include "PhoneBook.hpp"

std::string trimSpaces(std::string str)
{
	size_t start = 0;
	size_t end = str.length() - 1;

	while (std::isspace(str[start]))
		start++;
	while (std::isspace(str[end]))
		end--;
	return (str.substr(start, end - start + 1));
}

bool checkPrintable(std::string command)
{
    for (size_t i = 0; i < command.length(); i++)
    {
        if (!std::isprint(command[i]))
            return (false);
    }
    return (true);
}

void printInvalid(std::string command)
{
    if (checkPrintable(command))
    {
        std::cout << "Invalid command" << std::endl;
        std::cout << trimSpaces(command) << ": is invalide command, try one of these: ADD, SEARCH, EXIT" << std::endl;
    }
    else
    {
        std::cout << "Invalid Inputs" << std::endl;
        std::cout << "try one of these: ADD, SEARCH, EXIT" << std::endl;
    }
}

int whitespaces(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isspace(str[i]))
			return (0);
	}
	return (1);
}


int NumberChecker(std::string &input)
{
	if (input.length() == 10 && input[0] == '0')
	{
		for (size_t i = 0; i < input.length(); i++)
		{
			if (!std::isdigit(input[i]))
				return (0);
		}
		return (1);
	}
	else if (input.length() == 13 && input[0] == '+' && input[1] == '2' && input[2] == '1' && input[3] == '2')
	{
		for (size_t i = 4; i < input.length(); i++)
		{
			if (!std::isdigit(input[i]))
				return (0);
		}
		return (1);
	}
	return (0);
}