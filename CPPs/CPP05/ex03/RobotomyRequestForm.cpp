#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), target(target) {
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), target(other.target) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const {
	return target;
}
void RobotomyRequestForm::setTarget(const std::string &target) {
	this->target = target;
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form) {
	os << "RobotomyRequestForm: " << form.getName() << ", Target: " << form.getTarget()
	   << ", Is signed: " << (form.getIsSigned() ? "Yes" : "No")
	   << ", Grade to sign: " << form.getGradeToSign()
	   << ", Grade to execute: " << form.getGradeToExecute();
	return os;
}

void RobotomyRequestForm::executeAction() const {
	std::cout << "Bzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" << std::endl;
	std::srand(time(0));
	bool random = std::rand() % 2;

	if (random) {
		std::cout << target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy failed for " << target << "." << std::endl;
	}
	std::cout << "RobotomyRequestForm executed" << std::endl;
}