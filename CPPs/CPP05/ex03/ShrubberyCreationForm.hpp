#ifndef SHUBBERYCREATIONFORM_HPP
#define SHUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
		void _createShrubbery() const;

	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
		~ShrubberyCreationForm();

		void executeAction() const;

		// getters and setters
		std::string getTarget() const;
		void setTarget(std::string target);
};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i);

#endif