#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        // Create Bureaucrat instances
        Bureaucrat bureaucrat1("Alice", 1);

        Form form1("Form A", 50, 100);

        std::cout << "====< Initial state: >====" << std::endl;
        std::cout << bureaucrat1 << std::endl;
        std::cout << form1 << std::endl;

        // Test signing forms
        std::cout << "====< Testing form signing: >====" << std::endl;
		form1.beSigned(bureaucrat1);
		std::cout << form1 << std::endl;
        bureaucrat1.signForm(form1);
		form1.beSigned(bureaucrat1);
		form1.beSigned(bureaucrat1);

        // Display final state
        std::cout << "====< Final state: >====" << std::endl;
        std::cout << form1 << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}