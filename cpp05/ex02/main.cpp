#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat pedro("Pedro", 1);
        Bureaucrat john("John", 40);
        Bureaucrat rick("Rick", 140);

        std::cout << "---- Testing ShrubberyCreationForm ----" << std::endl;
        ShrubberyCreationForm shrubForm("Garden");
        shrubForm.beSigned(pedro);
        pedro.executeForm(shrubForm);
        std::cout << std::endl;

        std::cout << "---- Testing RobotomyRequestForm ----" << std::endl;
        RobotomyRequestForm roboForm("Marvin");
        roboForm.beSigned(john);
        roboForm.execute(john);
        roboForm.execute(john); // Try multiple times to see both outcomes
        roboForm.execute(john);
        roboForm.execute(john);
        std::cout << std::endl;

        std::cout << "---- Testing PresidentialPardonForm ----" << std::endl;
        PresidentialPardonForm pardonForm("Target");
        pardonForm.beSigned(pedro); // comment this line to test fail "not signed"
        pardonForm.execute(pedro);
        std::cout << std::endl;
        std::cout << shrubForm << std::endl;
        std::cout << roboForm << std::endl;
        std::cout << pardonForm << std::endl;

        // Try a failure case
        /*std::cout << "---- Testing Execution Failure (grade too low) ----" << std::endl;
        ShrubberyCreationForm failForm("fail");
        failForm.beSigned(rick);
        failForm.execute(rick); // Should throw GradeTooLowException*/


    }
    catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
