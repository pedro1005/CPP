#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeSign;
        const int           _gradeExe;
    
    public:
        AForm(void);
        AForm(const std::string &name, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm &copy);
        virtual ~AForm(void);

        virtual void execute(Bureaucrat const &executor) const = 0;
        virtual std::string getTarget() const = 0;


        AForm &operator = (const AForm &copy);

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

        class FormNotSignedException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

// Operator overloads
std::ostream &operator << (std::ostream &out, AForm const &form);

#endif