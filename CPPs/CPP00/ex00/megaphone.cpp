#include <iostream>

std::string myToUpper(const char *s)
{
	std::string str = s;
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
	return str;
}

int main(int ac, char **av)
{
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < ac; i++)
		std::cout << myToUpper(av[i]);
	std::cout << std::endl;
	return 0;
}
