#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 20

int main(void)
{
    {
        std::cout << "===== SUBJECT TEST =====" << std::endl;
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        
        // Test copy constructor and assignment operator
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        // Test values match
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        
        // Test exception handling for out of bounds access
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Exception caught for negative index: " << e.what() << std::endl;
        }
        
        try
        {
            numbers[MAX_VAL - 1] = 661166;
			std::cout << "Accessing index " << MAX_VAL - 1 << " and it hast his value: " << numbers[MAX_VAL - 1] << std::endl;
			std::cout << "Now it is going to fail by accessing index " << MAX_VAL << std::endl;
			numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Exception caught for index = MAX_VAL: " << e.what() << std::endl;
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        
        delete [] mirror;
    }
    
    // Additional tests
    {
        std::cout << "\n===== ADDITIONAL TESTS =====" << std::endl;
        
        // Test empty array
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;
        try
        {
            std::cout << emptyArray[0] << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
        
        // Test with different types
        // String array
        Array<std::string> stringArray(3);
        stringArray[0] = "Hello";
        stringArray[1] = "World";
        stringArray[2] = "!";
        
        std::cout << "String array contents: ";
        for (unsigned int i = 0; i < stringArray.size(); i++)
            std::cout << stringArray[i] << " ";
        std::cout << std::endl;
        
        // Char array
        Array<char> charArray(5);
        charArray[0] = 'H';
        charArray[1] = 'e';
        charArray[2] = 'l';
        charArray[3] = 'l';
        charArray[4] = 'o';
        
        std::cout << "Char array contents: ";
        for (unsigned int i = 0; i < charArray.size(); i++)
            std::cout << charArray[i];
        std::cout << std::endl;
        
        // Test deep copy
        Array<int> original(3);
        original[0] = 1;
        original[1] = 2;
        original[2] = 3;
        
        Array<int> copy = original;
        
        std::cout << "Original array: ";
        for (unsigned int i = 0; i < original.size(); i++)
            std::cout << original[i] << " ";
        std::cout << std::endl;
        
        std::cout << "Copy array (before modification): ";
        for (unsigned int i = 0; i < copy.size(); i++)
            std::cout << copy[i] << " ";
        std::cout << std::endl;
        
        // Modify the copy
        copy[0] = 100;
        copy[1] = 200;
        copy[2] = 300;
        
        std::cout << "Original array (after copy modification): ";
        for (unsigned int i = 0; i < original.size(); i++)
            std::cout << original[i] << " ";
        std::cout << std::endl;
        
        std::cout << "Copy array (after modification): ";
        for (unsigned int i = 0; i < copy.size(); i++)
            std::cout << copy[i] << " ";
        std::cout << std::endl;
    }
    
    return 0;
}
