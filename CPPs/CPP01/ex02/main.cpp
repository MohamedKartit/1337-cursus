# include <iostream>

int main() {
    // creating a string variable
    std::string staringVar = "HI THIS IS BRAIN";

    // creating a pointer to the string variable
    std::string *stringPTR = &staringVar;

    // creating a reference to the string variable
    std::string &stringREF = staringVar;

    // printing the address of the string variable, the pointer and the reference
    std::cout << "Address of string: " << &staringVar << std::endl;
    std::cout << "Address of stringPTR: " << stringPTR << std::endl;
    std::cout << "Address of stringREF: " << &stringREF << std::endl;

    // printing the value of the string variable, the pointer and the reference
    std::cout << "Value of string: " << staringVar << std::endl;
    std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value of stringREF: " << stringREF << std::endl;

    return 0;
}