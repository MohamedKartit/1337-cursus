#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
    // Test with vector
    std::cout << "===== Testing with std::vector =====" << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Value found in vector: " << *it << std::endl;
        std::cout << "Position: " << std::distance(vec.begin(), it) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 100);
        std::cout << "Value found in vector: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    // Test with list
    std::cout << "\n===== Testing with std::list =====" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);
    lst.push_back(35);
    lst.push_back(45);
    
    try
    {
        std::list<int>::iterator it = easyfind(lst, 25);
        std::cout << "Value found in list: " << *it << std::endl;
        std::cout << "Position: " << std::distance(lst.begin(), it) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    try
    {
        std::list<int>::iterator it = easyfind(lst, 100);
        std::cout << "Value found in list: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    // Test with deque
    std::cout << "\n===== Testing with std::deque =====" << std::endl;
    std::deque<int> deq;
    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);
    deq.push_back(4);
    deq.push_back(5);
    
    try
    {
        std::deque<int>::iterator it = easyfind(deq, 3);
        std::cout << "Value found in deque: " << *it << std::endl;
        std::cout << "Position: " << std::distance(deq.begin(), it) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    try
    {
        std::deque<int>::iterator it = easyfind(deq, 100);
        std::cout << "Value found in deque: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    // Test with const container
    std::cout << "\n===== Testing with const container =====" << std::endl;
    const std::vector<int> constVec(vec);
    
    try
    {
        std::vector<int>::const_iterator it = easyfind(constVec, 40);
        std::cout << "Value found in const vector: " << *it << std::endl;
        std::cout << "Position: " << std::distance(constVec.begin(), it) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}
