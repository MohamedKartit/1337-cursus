#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

class ScalarConverter
{
	private:
		// Make constructor private to prevent instantiation
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);

		// Helper functions
		static bool isChar(const std::string &literal);
		static bool isInt(const std::string &literal);
		static bool isFloat(const std::string &literal);
		static bool isDouble(const std::string &literal);
		static bool isPseudoLiteral(const std::string &literal);
		
		// Conversion functions
		static void convertFromChar(char c);
		static void convertFromInt(int i);
		static void convertFromFloat(float f);
		static void convertFromDouble(double d);
		static void convertFromPseudoLiteral(const std::string &literal);

	public:
		static void convert(const std::string &literal);
};

#endif