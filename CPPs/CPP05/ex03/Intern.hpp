#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
#include <exception>

class Intern {
	private:
		AForm* createPresidentialPardonForm(const std::string &target);
		AForm* createRobotomyRequestForm(const std::string &target);
		AForm* createShrubberyCreationForm(const std::string &target);

	public:
		Intern();
		Intern(const Intern &src);
		~Intern();
		Intern &operator=(const Intern &rhs);

		AForm* makeForm(const std::string &formName, const std::string &target);

		class FormNotFoundException : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif