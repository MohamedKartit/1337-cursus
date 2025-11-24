#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include "Span.hpp"

int main()
{
    // Test with the example from the subject
    std::cout << "===== SUBJECT TEST =====" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    // Test with a larger number of elements
    std::cout << "\n===== LARGE SPAN TEST =====" << std::endl;
    Span largeSpan(10000);
    
    // Fill the span with random numbers
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    for (int i = 0; i < 10000; ++i)
    {
        largeSpan.addNumber(std::rand() % 1000000);
    }
    
    std::cout << "Shortest span in large span: " << largeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span in large span: " << largeSpan.longestSpan() << std::endl;
    
    // Test adding a range of numbers
    std::cout << "\n===== RANGE ADDITION TEST =====" << std::endl;
    Span rangeSpan(10);
    std::list<int> numbers;
    
    for (int i = 1; i <= 10; ++i)
        numbers.push_back(i * 10);
    
    rangeSpan.addRange(numbers.begin(), numbers.end());
    
    std::cout << "Shortest span in range span: " << rangeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span in range span: " << rangeSpan.longestSpan() << std::endl;
    
    // Test error cases
    std::cout << "\n===== ERROR CASES =====" << std::endl;
    
    // Test adding too many numbers
    Span smallSpan(2);
    smallSpan.addNumber(1);
    smallSpan.addNumber(2);
    
    try
    {
        std::cout << "Trying to add a number to a full span..." << std::endl;
        smallSpan.addNumber(3);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    // Test finding span with not enough numbers
    Span emptySpan(5);
    
    try
    {
        std::cout << "Trying to find shortest span in an empty span..." << std::endl;
        emptySpan.shortestSpan();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    try
    {
        std::cout << "Trying to find longest span in an empty span..." << std::endl;
        emptySpan.longestSpan();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    // Test with a single number
    Span singleSpan(5);
    singleSpan.addNumber(42);
    
    try
    {
        std::cout << "Trying to find shortest span with a single number..." << std::endl;
        singleSpan.shortestSpan();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    // Test adding too many numbers using addRange
    Span limitedSpan(5);
    std::list<int> tooManyNumbers;
    
    for (int i = 1; i <= 10; ++i)
        tooManyNumbers.push_back(i);
    
    try
    {
        std::cout << "Trying to add too many numbers using addRange..." << std::endl;
        limitedSpan.addRange(tooManyNumbers.begin(), tooManyNumbers.end());
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}
