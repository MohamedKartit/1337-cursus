#include "Intern.hpp"
#include <algorithm>
#include <cctype>

Intern::Intern() {
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &src) {
	(void)src;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &rhs) {
	if (this != &rhs) {
		std::cout << "Intern assignment operator called" << std::endl;
	}
	return *this;
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
	static const std::string formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	static AForm* (Intern::*formCreators[3])(const std::string&) = {
		&Intern::createPresidentialPardonForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createShrubberyCreationForm
	};

	std::string lowerFormName = formName;
	std::transform(lowerFormName.begin(), lowerFormName.end(), lowerFormName.begin(), ::tolower);

	for (int i = 0; i < 3; ++i) {
		if (lowerFormName == formNames[i]) {
			return (this->*formCreators[i])(target);
		}
	}
	throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() {
	return "Intern: Form not found";
}

AForm* Intern::createPresidentialPardonForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyCreationForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

// The create*Form methods are private and are used to create specific forms.
