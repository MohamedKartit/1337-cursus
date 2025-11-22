#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "AForm constructor called for " << name << std::endl;
}

AForm::AForm(const AForm& other)
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	std::cout << "AForm copy constructor called for " << name << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
		isSigned = other.isSigned;
	return *this;
}

AForm::~AForm() {
	std::cout << "AForm destructor called for " << name << std::endl;
}

const std::string& AForm::getName() const {
	return name;
}

bool AForm::getIsSigned() const {
	return isSigned;
}

void AForm::setIsSigned(bool isSigned) {
	this->isSigned = isSigned;
}

int AForm::getGradeToSign() const {
	return gradeToSign;
}

int AForm::getGradeToExecute() const {
	return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > gradeToSign)
		throw AForm::GradeTooLowException();
	if (isSigned)
		std::cout << "AForm: " << name << " is already signed." << std::endl;
	else {
		isSigned = true;
		std::cout << bureaucrat.getName() << " signed " << name << std::endl;
	}
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "AForm grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "AForm grade is too low";
}

void AForm::execute(const Bureaucrat& executor) const {
	if (!isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw AForm::GradeTooLowException();
	executeAction();
	std::cout << executor.getName() << " executed " << name << std::endl;
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "AForm: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
	   << ", Grade to sign: " << form.getGradeToSign()
	   << ", Grade to execute: " << form.getGradeToExecute();
	return os;
}