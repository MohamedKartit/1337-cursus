#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{/*Nothing*/}
	return *this;
}

void ScalarConverter::convert(const std::string &literal)
{
	if (isPseudoLiteral(literal))
	{
		convertFromPseudoLiteral(literal);
		return;
	}
	if (isChar(literal))
	{
		convertFromChar(literal[0]);
	}
	else if (isInt(literal))
	{
		convertFromInt(std::atoi(literal.c_str()));
	}
	else if (isFloat(literal))
	{
		convertFromFloat(std::atof(literal.c_str()));
	}
	else if (isDouble(literal))
	{
		convertFromDouble(std::atof(literal.c_str()));
	}
	else
	{
		std::cerr << "Invalid literal" << std::endl;
	}
}

bool ScalarConverter::isChar(const std::string &literal)
{
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string &literal)
{
	if (literal.empty())
		return false;
	
	size_t i = 0;
	if (literal[0] == '-' || literal[0] == '+')
		i++;
	
	for (; i < literal.length(); ++i)
	{
		if (!isdigit(literal[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string &literal)
{
	if (literal.empty() || literal[literal.length() - 1] != 'f')
		return false;
	
	std::string withoutF = literal.substr(0, literal.length() - 1);
	bool hasDot = false;
	size_t i = 0;
	if (withoutF[0] == '-' || withoutF[0] == '+')
		i++;
	
	for (; i < withoutF.length(); ++i)
	{
		if (withoutF[i] == '.' && !hasDot)
			hasDot = true;
		else if (!isdigit(withoutF[i]))
			return false;
	}
	return hasDot;
}

bool ScalarConverter::isDouble(const std::string &literal)
{
	if (literal.empty())
		return false;
	
	bool hasDot = false;
	size_t i = 0;
	if (literal[0] == '-' || literal[0] == '+')
		i++;
	
	for (; i < literal.length(); ++i)
	{
		if (literal[i] == '.' && !hasDot)
			hasDot = true;
		else if (!isdigit(literal[i]))
			return false;
	}
	return hasDot;
}

bool ScalarConverter::isPseudoLiteral(const std::string &literal)
{
	return (literal == "nan" || literal == "nanf" ||
			literal == "+inf" || literal == "+inff" ||
			literal == "-inf" || literal == "-inff");
}

void ScalarConverter::convertFromChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(int i)
{
	if (i >= 32 && i <= 126)
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::convertFromFloat(float f)
{
	if (std::isnan(f) || std::isinf(f))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (f >= 32 && f <= 126)
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		
		if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(f) << std::endl;
	}
	
	std::cout << "float: " << f;
	if (f == static_cast<int>(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;
	
	std::cout << "double: " << static_cast<double>(f);
	if (f == static_cast<int>(f))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convertFromDouble(double d)
{
	if (std::isnan(d) || std::isinf(d))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (d >= 32 && d <= 126)
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		
		if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;
	}
	
	std::cout << "float: " << static_cast<float>(d);
	if (d == static_cast<int>(d))
		std::cout << ".0";
	std::cout << "f" << std::endl;
	
	std::cout << "double: " << d;
	if (d == static_cast<int>(d))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convertFromPseudoLiteral(const std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

