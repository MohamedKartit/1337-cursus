#include <iostream>
#include <string>
#include "iter.hpp"

// Template function to print any type
template <typename T>
void printElement(T const &element)
{
    std::cout << element << " ";
}

// Function to multiply integers by 2
void multiplyByTwo(int &num)
{
    num *= 2;
}

// Function to convert characters to uppercase
void toUppercase(char &c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
}

int main(void)
{
    // Test with an array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = 5;
    
    std::cout << "Original int array: ";
    iter(intArray, intArrayLength, printElement);
    std::cout << std::endl;
    
    // Apply a function that modifies the array
    iter(intArray, intArrayLength, multiplyByTwo);
    
    std::cout << "After multiplying by 2: ";
    iter(intArray, intArrayLength, printElement);
    std::cout << std::endl;
    
    // Test with an array of strings
    std::string stringArray[] = {"Hello", "World", "C++", "Templates"};
    size_t stringArrayLength = 4;
    
    std::cout << "String array: ";
    iter(stringArray, stringArrayLength, printElement);
    std::cout << std::endl;
    
    // Test with an array of characters
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charArrayLength = 5;
    
    std::cout << "Original char array: ";
    iter(charArray, charArrayLength, printElement);
    std::cout << std::endl;
    
    // Apply a function that modifies the array
    iter(charArray, charArrayLength, toUppercase);
    
    std::cout << "After converting to uppercase: ";
    iter(charArray, charArrayLength, printElement);
    std::cout << std::endl;
    
    return 0;
}
