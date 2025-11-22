#include "Bureaucrat.hpp"

int main() {
	// increment test;
	try {
		Bureaucrat incBureau("John Doe", 2);
		std::cout << incBureau << std::endl;
        for (int i = 0; i < 10; ++i) {
            incBureau.incrementGrade();
            std::cout << "Incremented grade: " << incBureau << std::endl;
        }
        std::cout << "Incremented grade: " << incBureau << std::endl;
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << e.what() << std::endl;
    }

	// decrement test
    try {
		Bureaucrat decBureau("Thrump", 147);
		for (int i = 0; i < 150; ++i) {
            decBureau.decrementGrade();
            std::cout << "Decremented grade: " << decBureau << std::endl;
        }
        std::cout << "Decremented grade: " << decBureau << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }

	try {
		Bureaucrat testBurea("med", 1);
		testBurea.incrementGrade();
	}
	catch (std::exception & e){
		std::cerr << e.what() << std::endl;
	}
    return 0;
}