#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeSign;
        const int           _gradeExe;
    
    public:
        Form(void);
        Form(const std::string &name, const int gradeToSign, const int gradeToExecute);
        Form(const Form &copy);
        ~Form(void);

        Form &operator = (const Form &copy);

        // Getters
        const std::string   &getName() const;
        bool                getSigned() const;
        int           getGradeSign() const;
        int           getGradeExec() const;
        
        // Member functions
        void                beSigned(Bureaucrat &bureaucrat);
        
        // Exception classes
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

// Operator overloads
std::ostream &operator << (std::ostream &out, Form const &form);

#endif