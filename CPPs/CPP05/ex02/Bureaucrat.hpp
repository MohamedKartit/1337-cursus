#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

class AForm;  // Forward declaration

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
		void checkGrade(int grade);

	public:
		// canonical form
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat();

		// getters
		std::string getName() const;
		int getGrade() const;

		// increment and decrement
		void incrementGrade();
		void decrementGrade();

		// form signing
		void signForm(AForm& form) const;
		void executeForm(const AForm& form) const;

		// exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif