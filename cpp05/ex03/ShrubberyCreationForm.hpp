#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;

    public:
        ShrubberyCreationForm(std::string const &target); // Parametrized Constructor
        ShrubberyCreationForm(const ShrubberyCreationForm &copy); // Copy Constructor
        virtual ~ShrubberyCreationForm(void); // Destructor

        ShrubberyCreationForm &operator = (const ShrubberyCreationForm &copy); // Copy Assignment Operator

        virtual void execute(Bureaucrat const &executor) const; // Execute function
        std::string getTarget() const;
};

#endif
