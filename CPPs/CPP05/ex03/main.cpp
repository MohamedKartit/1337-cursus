#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try {
		// Create an intern
		Intern intern;
		
		// Create a bureaucrat
		Bureaucrat bureaucrat("Bureaucrat", 1);
		
		// Test creating different forms
		std::cout << "\n--- Testing form creation ---" << std::endl;
		
		// Test ShrubberyCreationForm
		AForm* shrubberyForm = intern.makeForm("shrubbery creation", "home");
		std::cout << "Created form: " << *shrubberyForm << std::endl;
		bureaucrat.signForm(*shrubberyForm);
		bureaucrat.executeForm(*shrubberyForm);
		delete shrubberyForm;
		
		// Test RobotomyRequestForm
		AForm* robotomyForm = intern.makeForm("robotomy request", "robot");
		std::cout << "Created form: " << *robotomyForm << std::endl;
		bureaucrat.signForm(*robotomyForm);
		bureaucrat.executeForm(*robotomyForm);
		delete robotomyForm;
		
		// Test PresidentialPardonForm
		AForm* presidentialForm = intern.makeForm("presidential pardon", "president");
		std::cout << "Created form: " << *presidentialForm << std::endl;
		bureaucrat.signForm(*presidentialForm);
		bureaucrat.executeForm(*presidentialForm);
		delete presidentialForm;
		
		// Test case insensitivity
		std::cout << "\n--- Testing case insensitivity ---" << std::endl;
		AForm* shrubberyForm2 = intern.makeForm("SHRUBBERY CREATION", "garden");
		std::cout << "Created form: " << *shrubberyForm2 << std::endl;
		delete shrubberyForm2;
		
		// Test non-existent form
		std::cout << "\n--- Testing non-existent form ---" << std::endl;
		try {
			AForm* nonExistentForm = intern.makeForm("non-existent form", "target");
			delete nonExistentForm; // This line should not be reached
		} catch (const Intern::FormNotFoundException& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	return 0;
}