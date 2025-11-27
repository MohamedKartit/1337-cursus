#include "PmergeMe.hpp"

bool isPositiveNumber(const std::string& str)
{
    bool dotSeen = false;
    if (str.empty()) return false;
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (str[i] == '.')
        {
            if (dotSeen) return false;
            dotSeen = true;
            continue;
        }
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

std::string formatWithSpaces(double number, int maxWidth)
{
    std::ostringstream oss;
    oss << number;
    std::string str = oss.str();
    int numSpaces = maxWidth - str.length();
    for (int i = 0; i < numSpaces; ++i)
    {
        str = " " + str;
    }
    return str;
}

std::string intToString(double number)
{
    std::ostringstream oss;
    oss << number;
    return oss.str();
}

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
        {
            std::cerr << "" << "Usage: " << argv[0] << " num1 num2 ... numN" << std::endl;
            return 1;
        }
        {
            std::vector<double> data;
            std::deque<double> deq;

            for (int i = 1; i < argc; ++i)
            {
                if (!isPositiveNumber(argv[i]))
                {
                    std::cerr << "" << "Error: Invalid input '" << argv[i] << "'. All inputs must be positive integers." << std::endl << std::endl;
                    return 1;
                }

                double num = std::strtod(argv[i], NULL);

                data.push_back(num);
                deq.push_back(num);
            }

            PmergeMe pmergeMe;
            pmergeMe.setData(data);
            pmergeMe.setDeq(deq);

            std::cout << "Before: ";
            for (std::vector<double>::iterator it = pmergeMe.getData().begin(); it != pmergeMe.getData().end(); ++it)
            {
                std::cout << *it << " ";
            }

            if (pmergeMe.getData().size() > 26)
                std::cout << std::endl;

            std::clock_t startVector = std::clock();
            sortsFordJohnson(pmergeMe.getData());
            std::clock_t endVector = std::clock();
            double durationVector = 1000000.0 * (endVector - startVector) / CLOCKS_PER_SEC;

            std::cout << "\nAfter: ";
            for (std::vector<double>::iterator it = pmergeMe.getData().begin(); it != pmergeMe.getData().end(); ++it)
            {
                std::cout << *it << " ";
            }

            if (pmergeMe.getData().size() > 26 || pmergeMe.getDeq().size() <= 10)
                std::cout << std::endl;

            std::clock_t startDeque = std::clock();
            sortsFordJohnson(pmergeMe.getDeq());
            std::clock_t endDeque = std::clock();
            double durationDeque = 1000000.0 * (endDeque - startDeque) / CLOCKS_PER_SEC;

            int maxWidth = std::max(intToString(durationVector).length(), intToString(durationDeque).length());

            std::cout << "Time to process a range of " << pmergeMe.getData().size() << " elements with std::vector : "
                      << formatWithSpaces(durationVector, maxWidth) << " us" << std::endl;
            std::cout << "Time to process a range of " << pmergeMe.getData().size() << " elements with std::deque  : "
                      << formatWithSpaces(durationDeque, maxWidth) << " us" << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "" << "Exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

/* main.cpp */