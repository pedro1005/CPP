#include "Form.hpp"

Form::Form(void)
    : _name("Default"), _signed(false), _gradeSign(150), _gradeExe(150) {}


Form::Form(const std::string &name, const int gradeToSign, const int gradeToExecute)
    : _name(name), _signed(false), _gradeSign(gradeToSign), _gradeExe(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &copy)
    : _name(copy._name), _signed(copy._signed),
      _gradeSign(copy._gradeSign), _gradeExe(copy._gradeExe) {}

Form::~Form(void) {}

// Assignment operator
Form &Form::operator = (const Form &copy) {
    if (this != &copy)
        _signed = copy._signed; // _name and grades are const — cannot assign them
    return *this;
}

// Getters
const std::string &Form::getName() const {
    return _name;
}

bool Form::getSigned() const {
    return _signed;
}

int Form::getGradeSign() const {
    return _gradeSign;
}

int Form::getGradeExec() const {
    return _gradeExe;
}

// beSigned: Bureaucrat signs form if grade is sufficient
void Form::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _signed = true;
}

// Exception what() definitions
const char* Form::GradeTooHighException::what() const throw() {
    return "Form: grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form: grade is too low!";
}

// Operator<< overload
std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << "Form " << form.getName() << " | Signed: "
        << (form.getSigned() ? "Yes" : "No")
        << " | Grade to Sign: " << form.getGradeSign()
        << " | Grade to Execute: " << form.getGradeExec();
    return out;
}
