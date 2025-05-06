#include "Intern.hpp"
#include <iostream>
#include <string>

int main()
{
    Intern intern;

    // Test valid forms
    AForm *form1 = intern.makeForm("shrubbery", "Target 1");
    std::cout << form1->getName() << " | target: " << form1->getTarget() << std::endl;
    AForm *form2 = intern.makeForm("robotomy", "Target 2");
    std::cout << form2->getName() << " | target: " << form2->getTarget() << std::endl;
    AForm *form3 = intern.makeForm("presidential", "Target 3");
    std::cout << form3->getName() << " | target: " << form3->getTarget() << std::endl;

    Bureaucrat b("B",1);
    form1->beSigned(b);
    b.executeForm(*form1);

    // Test invalid form
    AForm *form4 = intern.makeForm("unknown", "Nobody");

    // Clean up allocated memory
    delete form1;
    delete form2;
    delete form3;
    (void)form4;

    return 0;
}
