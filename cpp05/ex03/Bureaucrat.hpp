#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string   _name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat(void);

		Bureaucrat &operator=(Bureaucrat const &copy);

		const std::string&	getName() const;
		int					getGrade() const;
		void				incGrade();
		void				decGrade();

		void				signForm(AForm &form);

		// Exception classes
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		void executeForm(AForm const &form) const;
		
};

std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat);

#endif