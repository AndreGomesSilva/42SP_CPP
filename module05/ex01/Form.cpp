#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : _name("default"), _signed(false), _gradeToSigned(150),
      _gradeToExecute(150) {}

Form::Form(const Form &copy)
    : _name(copy._name), _signed(copy._signed),
      _gradeToSigned(copy._gradeToSigned),
      _gradeToExecute(copy._gradeToExecute) {};

Form::~Form() {};

Form &Form::operator=(const Form &copy) {
  if (this != &copy) {
    _signed = copy._signed;
  }
  return *this;
}

const std::string Form::getName(void) const { return this->_name; }

bool Form::hasSigned(void) const { return this->_signed; }

const unsigned int Form::getGradeToSigned(void) { return this->_gradeToSigned; }

const unsigned int Form::getGradeToExecute(void) {
  return this->_gradeToExecute;
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade is too low!";
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade is too hight!";
}
