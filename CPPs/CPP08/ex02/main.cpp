#include <iostream>
#include <list>
#include <vector>
#include "MutantStack.hpp"

// int main()
// {
//     // Test with the example from the subject
//     std::cout << "===== SUBJECT TEST WITH MUTANTSTACK =====" << std::endl;
//     MutantStack<int> mstack;
    
//     mstack.push(5);
//     mstack.push(17);
    
//     std::cout << "Top: " << mstack.top() << std::endl;
    
//     mstack.pop();
    
//     std::cout << "Size: " << mstack.size() << std::endl;
    
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     mstack.push(0);
    
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
    
//     ++it;
//     --it;
    
//     std::cout << "Stack contents:" << std::endl;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
    
//     // Test with std::list for comparison
//     std::cout << "\n===== SUBJECT TEST WITH STD::LIST =====" << std::endl;
//     std::list<int> lst;
    
//     lst.push_back(5);
//     lst.push_back(17);
    
//     std::cout << "Back: " << lst.back() << std::endl;
    
//     lst.pop_back();
    
//     std::cout << "Size: " << lst.size() << std::endl;
    
//     lst.push_back(3);
//     lst.push_back(5);
//     lst.push_back(737);
//     lst.push_back(0);
    
//     std::list<int>::iterator lst_it = lst.begin();
//     std::list<int>::iterator lst_ite = lst.end();
    
//     ++lst_it;
//     --lst_it;
    
//     std::cout << "List contents:" << std::endl;
//     while (lst_it != lst_ite)
//     {
//         std::cout << *lst_it << std::endl;
//         ++lst_it;
//     }
    
//     // Additional tests
//     std::cout << "\n===== ADDITIONAL TESTS =====" << std::endl;
    
//     // Test with different container type (vector)
//     std::cout << "\n1. MutantStack with std::vector as container:" << std::endl;
//     MutantStack<int, std::vector<int> > vstack;
    
//     for (int i = 1; i <= 5; ++i)
//         vstack.push(i * 10);
    
//     std::cout << "Vector-based stack contents:" << std::endl;
//     for (MutantStack<int, std::vector<int> >::iterator it = vstack.begin(); it != vstack.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;
    
//     // Test with const iterators
//     std::cout << "\n2. Testing const iterators:" << std::endl;
//     const MutantStack<int> const_mstack(mstack);
    
//     std::cout << "Const stack contents:" << std::endl;
//     for (MutantStack<int>::const_iterator it = const_mstack.begin(); it != const_mstack.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;
    
//     // Test with reverse iterators
//     std::cout << "\n3. Testing reverse iterators:" << std::endl;
//     std::cout << "Reverse stack contents:" << std::endl;
//     for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;
    
//     // Test with different data type
//     std::cout << "\n4. Testing with string data type:" << std::endl;
//     MutantStack<std::string> sstack;
    
//     sstack.push("Hello");
//     sstack.push("World");
//     sstack.push("C++");
//     sstack.push("Templates");
    
//     std::cout << "String stack contents:" << std::endl;
//     for (MutantStack<std::string>::iterator it = sstack.begin(); it != sstack.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;
    
//     // Test copy constructor and assignment operator
//     std::cout << "\n5. Testing copy constructor and assignment operator:" << std::endl;
    
//     MutantStack<int> copy_stack(mstack);
//     std::cout << "Copy stack contents:" << std::endl;
//     for (MutantStack<int>::iterator it = copy_stack.begin(); it != copy_stack.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;
    
//     MutantStack<int> assign_stack;
//     assign_stack = mstack;
//     std::cout << "Assigned stack contents:" << std::endl;
//     for (MutantStack<int>::iterator it = assign_stack.begin(); it != assign_stack.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;
    
//     // Verify that std::stack can be constructed from MutantStack
//     std::cout << "\n6. Testing std::stack construction from MutantStack:" << std::endl;
//     std::stack<int> s(mstack);
//     std::cout << "Size of std::stack constructed from MutantStack: " << s.size() << std::endl;
    
//     return 0;
// }

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}