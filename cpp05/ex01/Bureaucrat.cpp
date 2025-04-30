#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy) {
    if (this != &copy)
        this->_grade = copy._grade;

    return *this;
}

Bureaucrat::~Bureaucrat(void) {}

// Getters
const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

// Grade increment (up)
void Bureaucrat::incGrade() {
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

// Grade decrement (down)
void Bureaucrat::decGrade() {
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

// Exception what() definitions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

// Output stream operator overload
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}

void Bureaucrat::signForm(Form &form)
{
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << _name << " couldn’t sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}