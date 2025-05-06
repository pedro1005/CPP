#include "Intern.hpp"

// Constructors / Destructor / Assignment
Intern::Intern(void) {}
Intern::Intern(const Intern &copy) { (void)copy; }
Intern::~Intern(void) {}
Intern &Intern::operator=(const Intern &copy)
{
    (void)copy;
    return *this;
}

// Private form creation functions
AForm *Intern::createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

// makeForm implementation
AForm *Intern::makeForm(const std::string &form, const std::string &target)
{
    std::string formNames[3] = {
        "shrubbery",
        "robotomy",
        "presidential"
    };

    // Array of pointers to Intern's member functions
    AForm *(Intern::*ft_ptr[3])(const std::string&) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; ++i)
    {
        if (form == formNames[i])
        {
            std::cout << "Intern creates " << formNames[i] << " form." << std::endl;
            return (this->*ft_ptr[i])(target);
        }
    }

    std::cout << "Form \"" << form << "\" not found." << std::endl;
    return NULL;
}
