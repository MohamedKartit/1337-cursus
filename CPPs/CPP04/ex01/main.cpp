#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	Cat		cat;
	Dog 	dog;
	Brain 	brain;

	std::cout << "--------< Cat's Brain test >-------" <<std::endl;
	cat.makeSound();
	std::cout << cat.getBrain()->getIdea() << std::endl;
	cat.getBrain()->setIdea("I am a cat");
	std::cout << cat.getBrain()->getIdea() << std::endl;

	std::cout << "--------< Dog's Brain test >-------" <<std::endl;
	dog.makeSound();
	std::cout << dog.getBrain()->getIdea() << std::endl;
	dog.getBrain()->setIdea("I am a dog");
	std::cout << dog.getBrain()->getIdea() << std::endl;

	std::cout << "--------< Brain test >-------" <<std::endl;

	std::cout << brain.getIdea() << std::endl;
	brain.setIdea("Who am i?");
	std::cout << brain.getIdea() << std::endl;
	std::cout << std::endl;

	// Dog dog;
	dog.getBrain()->setIdea("I am a dog");
	Dog dog2(dog);
	std::cout << dog2.getBrain()->getIdea() << std::endl;
	std::cout << dog.getBrain()->getIdea() << std::endl;

	dog2 = dog;
	std::cout << dog2.getBrain()->getIdea() << std::endl;
	std::cout << dog.getBrain()->getIdea() << std::endl;

	dog2.getBrain()->setIdea("I am a dog2");
	std::cout << dog2.getBrain()->getIdea() << std::endl;
	std::cout << dog.getBrain()->getIdea() << std::endl;

	// Cat cat;
	cat.getBrain()->setIdea("I am a cat");
	Cat cat2(cat);
	std::cout << cat2.getBrain()->getIdea() << std::endl;
	std::cout << cat.getBrain()->getIdea() << std::endl;

	cat2 = cat;
	std::cout << cat2.getBrain()->getIdea() << std::endl;
	std::cout << cat.getBrain()->getIdea() << std::endl;

	cat2.getBrain()->setIdea("I am a cat2");
	std::cout << cat2.getBrain()->getIdea() << std::endl;
	std::cout << cat.getBrain()->getIdea() << std::endl;

	return 0;
}