#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try {
		// Create bureaucrats with different grades
		Bureaucrat highGrade("High Grade", 1);
		Bureaucrat lowGrade("Low Grade", 150);

		// Create forms
		ShrubberyCreationForm shrubberyForm("home");
		RobotomyRequestForm robotomyForm("robot");
		PresidentialPardonForm presidentialForm("president");

		std::cout << "\nInitial state:" << std::endl;
		std::cout << highGrade << std::endl;
		std::cout << lowGrade << std::endl;
		std::cout << shrubberyForm << std::endl;
		std::cout << robotomyForm << std::endl;
		std::cout << presidentialForm << std::endl;

		// Test signing forms
		std::cout << "\nTesting form signing:" << std::endl;
		highGrade.signForm(shrubberyForm);
		highGrade.signForm(robotomyForm);
		highGrade.signForm(presidentialForm);
		lowGrade.signForm(shrubberyForm);  // Should fail

		// Test executing forms
		std::cout << "\nTesting form execution:" << std::endl;
		highGrade.executeForm(shrubberyForm);
		highGrade.executeForm(robotomyForm);
		highGrade.executeForm(presidentialForm);
		lowGrade.executeForm(shrubberyForm);  // Should fail

		// Test executing unsigned form
		ShrubberyCreationForm unsignedForm("unsigned");
		highGrade.executeForm(unsignedForm);  // Should fail

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}