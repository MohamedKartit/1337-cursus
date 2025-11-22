#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src), _target(src._target) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this != &rhs) {
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::_createShrubbery() const {
	std::ofstream file(_target + "_shrubbery");
	if (!file) {
		std::cerr << "Error: Could not open file " << _target + "_shrubbery" << std::endl;
		return;
	}
	file << "                      ___\n"
			"                _,-'\"\"   \"\"\"\"`--.\n"
			"             ,-'          __,,-- \\\n"
			"           ,'    __,--\"\"\"\"dF      )\n"
			"          /   .-\"Hb_,--\"\"dF      /\n"
			"        ,'       _Hb ___dF\"-._,-'\n"
			"      ,'      _,-\"\"\"\"   \"\"--..__\n"
			"     (     ,-'                  `.\n"
			"      `._,'     _   _             ;\n"
			"       ,'     ,' `-'Hb-.___..._,-'\n"
			"       \\    ,'\"Hb.-'HH`-.dHF\"\n"
			"        `--'   \"Hb  HH  dF\"\n"
			"                \"Hb HH dF\n"
			"                 \"HbHHdF\n"
			"                  |HHHF\n"
			"                  |HHH|\n"
			"                  |HHH|\n"
			"                  |HHH|\n"
			"                  |HHH|\n"
			"                  dHHHb\n"
			"                .dFd|bHb.               o\n"
			"      o       .dHFdH|HbTHb.          o /\n"
			"\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y\n"
			"##########################################\n";
	file.close();
}

void ShrubberyCreationForm::executeAction() const {
	_createShrubbery();
	std::cout << "Shrubbery created at " << _target + "_shrubbery" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const {
	return _target;
}

void ShrubberyCreationForm::setTarget(std::string target) {
	_target = target;
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form) {
	os << "ShrubberyCreationForm: " << form.getName() << ", Target: " << form.getTarget()
	   << ", Is signed: " << (form.getIsSigned() ? "Yes" : "No")
	   << ", Grade to sign: " << form.getGradeToSign()
	   << ", Grade to execute: " << form.getGradeToExecute();
	return os;
}