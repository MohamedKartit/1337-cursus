#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data* original = new Data;
    original->name = "Test";
    original->value = 42;
    original->score = 3.14;

    std::cout << "Original Data:" << std::endl;
    std::cout << "Name: " << original->name << std::endl;
    std::cout << "Value: " << original->value << std::endl;
    std::cout << "Score: " << original->score << std::endl;

    uintptr_t serialized = Serializer::serialize(original);
    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Value: " << deserialized->value << std::endl;
    std::cout << "Score: " << deserialized->score << std::endl;

    delete original;
    return 0;
} 