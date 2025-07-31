#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
    try {

		// Test: Attempt to create a Form with invalid grade (should throw)
        //Form badForm1("BadForm1", 0, 150);
		//Form badForm2("BadForm2", 151, 200);
		//Form badForm3("BadForm3", 1, 0);
		//Form badForm4("BadForm4", 1, 151);

        Bureaucrat bob("Bob", 50);

        Form contractA("Contract A", 20, 150);
        Form contractB("Contract B", 60, 150);

        std::cout << std::endl;

        // Test: Bob signs contract B (should succeed)
        std::cout << "Bob's grade: " << bob.getGrade() << std::endl;
        std::cout << "Contract B required grade to sign: " << contractB.getGradeSign() << std::endl;
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
