#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

// Parametrized Constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm("Shrubbery Creation", 145, 137), _target(target) {}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : AForm(copy), _target(copy._target) {}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

// Copy Assignment Operator
ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &copy) {
    if (this != &copy) {
        AForm::operator = (copy);
        _target = copy._target;
    }
    return *this;
}

// Execute function
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!getSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeExec())
        throw GradeTooLowException();
    try {
        std::ofstream file((_target + "_shrubbery").c_str());
        if (!file)
            throw std::runtime_error("Failed to open output file for shrubbery");

        file << "        v .   ._, |_  .,\n"
             << "     `-._\\/  .  \\ /    |/_\n"
             << "         \\\\  _\\, y | \\//\n"
             << "   _\\_.___\\\\, \\\\/ -.\\||\n"
             << "     `7-,--.`._||  / / ,\n"
             << "     /'     `-. `./ / |/_.'\n"
             << "               |    |//\n"
             << "               |_    /\n"
             << "               |-   |\n"
             << "               |   =|\n"
             << "               |    |\n"
             << "-----------------------------\n"
             << "Bureaucrat : " << executor.getName() << " | Form: " << this->getName() << std::endl
             << "Yes, this tree was designed with ChatGPT!\n";
        file.close();

        std::cout << executor.getName() << " executed ShrubberyCreationForm for " << _target << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Error while executing form: " << e.what() << std::endl;
    }
}

std::string ShrubberyCreationForm::getTarget() const {
    return _target;
}
