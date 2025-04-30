#include "AForm.hpp"

AForm::AForm(void)
    : _name("Default"), _signed(false), _gradeSign(150), _gradeExe(150) {}


AForm::AForm(const std::string &name, const int gradeToSign, const int gradeToExecute)
    : _name(name), _signed(false), _gradeSign(gradeToSign), _gradeExe(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &copy)
    : _name(copy._name), _signed(copy._signed),
      _gradeSign(copy._gradeSign), _gradeExe(copy._gradeExe) {}

AForm::~AForm(void) {}

// Assignment operator
AForm &AForm::operator = (const AForm &copy) {
    if (this != &copy)
        _signed = copy._signed; // _name and grades are const — cannot assign them
    return *this;
}

// Getters
const std::string &AForm::getName() const {
    return _name;
}

bool AForm::getSigned() const {
    return _signed;
}

int AForm::getGradeSign() const {
    return _gradeSign;
}

int AForm::getGradeExec() const {
    return _gradeExe;
}

// beSigned: Bureaucrat signs form if grade is sufficient
void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _signed = true;
}

// Exception what() definitions
const char* AForm::GradeTooHighException::what() const throw() {
    return "Form: grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form: grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

// Operator<< overload
std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << "Form " << form.getName() << " | Signed: "
        << (form.getSigned() ? "Yes" : "No")
        << " | Grade to Sign: " << form.getGradeSign()
        << " | Grade to Execute: " << form.getGradeExec();
    return out;
}
