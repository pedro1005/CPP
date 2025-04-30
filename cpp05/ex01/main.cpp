#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
    try {

		// Test: Attempt to create a Form with invalid grade (should throw)
        //Form badForm("BadForm", 0, 150);
		//Form badForm("BadForm", 151, 200);
		//Form badForm("BadForm", 1, 0);
		//Form badForm("BadForm", 1, 151);

        Bureaucrat bob("Bob", 50);

        Form contractA("Contract A", 20, 150);
        Form contractB("Contract B", 60, 150);

        std::cout << std::endl;

        // Test: Bob signs contract B (should succeed)
        bob.signForm(contractB);
        std::cout << contractB << std::endl;

        std::cout << std::endl;

        // Test: Bob signs Contract A (should fail)
        bob.signForm(contractA);
        std::cout << contractA << std::endl;

    }
    catch (std::exception &e) {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}
