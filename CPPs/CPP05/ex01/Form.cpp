#include "Form.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "Form constructor called for " << name << std::endl;
}

Form::Form(const Form& other)
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	std::cout << "Form copy constructor called for " << name << std::endl;
}

Form& Form::operator=(const Form& other) {
	if (this != &other)
		isSigned = other.isSigned;
	return *this;
}

Form::~Form() {
	std::cout << "Form destructor called for " << name << std::endl;
}

const std::string& Form::getName() const {
	return name;
}

bool Form::getIsSigned() const {
	return isSigned;
}

void Form::setIsSigned(bool isSigned) {
	this->isSigned = isSigned;
}

int Form::getGradeToSign() const {
	return gradeToSign;
}

int Form::getGradeToExecute() const {
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > gradeToSign)
		throw Form::GradeTooLowException();
	if (isSigned)
		std::cout << "Form: " << name << " is already signed." << std::endl;
	else {
		isSigned = true;
		std::cout << bureaucrat.getName() << " signed " << name << std::endl;
	}
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Form grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
	   << ", Grade to sign: " << form.getGradeToSign()
	   << ", Grade to execute: " << form.getGradeToExecute();
	return os;
}
