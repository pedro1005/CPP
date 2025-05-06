#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

class Intern
{
public:
    Intern(void);
    Intern(const Intern &copy);
    ~Intern(void);
    Intern &operator=(const Intern &copy);

    AForm *makeForm(const std::string &form, const std::string &target);

private:
    // Private creation methods for each form
    AForm *createShrubbery(const std::string &target);
    AForm *createRobotomy(const std::string &target);
    AForm *createPresidential(const std::string &target);
};

#endif
