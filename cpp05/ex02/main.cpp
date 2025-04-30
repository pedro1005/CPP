#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
    try {
        // Create Bureaucrats with Portuguese names
        Bureaucrat joao("João", 137);

        // Create ShrubberyCreationForm
        ShrubberyCreationForm form("arvore");

        // Try signing the form
        joao.signForm(form);

        // Output form status
        std::cout << form << std::endl;

        // Try executing the form
        joao.executeForm(form); // João can execute it because his grade (100) is good enough

    } catch (const std::exception &e) {
        std::cout << "Exceção: " << e.what() << std::endl;
    }

    return 0;
}

