#include "Form.hpp"

Form::Form()
    : _name("default"), _signed(false), _gradeToSign(150),
      _gradeToExecute(150) {
  std::cout << "default " << *this << " was created " << std::endl;
}

Form::Form(std::string name, unsigned int gradeToSign,
           unsigned int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1)
    throw(Form::GradeTooHighException());
  else if (gradeToSign > 150 || gradeToExecute > 150)
    throw(Form::GradeTooLowException());
  else {
    std::cout << *this << " was created " << std::endl;
  };
}

Form::Form(const Form &copy)
    : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign),
      _gradeToExecute(copy._gradeToExecute) {

  std::cout << *this << " was copied " << std::endl;
};

Form::~Form() {
  std::cout << *this << " was deleted " << std::endl;
};

Form &Form::operator=(const Form &copy) {
  if (this != &copy) {
    _signed = copy._signed;
    std::cout << *this << " was copied " << std::endl;
  }
  return *this;
}

std::ostream &operator<<(std::ostream &os, Form const &Form) {
  std::string sign = "not sign";

  if (Form.hasSigned()) {
    sign = "signed";
  }
  os << "Formulario: " << Form.getName() << ", is: " << sign
     << ", grade to sign: " << Form.getGradeToSigned()
     << ", grade to execute: " << Form.getGradeToExecute() << ".";
  return os;
}

void Form::beSigned(Bureaucrat &Bureaucrat) {
  unsigned int bureaucratGrade = Bureaucrat.getGrade();
  if (this->_signed == false) {
    {
      if (bureaucratGrade > this->getGradeToSigned()) {
        throw(Form::GradeTooLowException());
      } else
        _signed = true;
    }
  } else {
    std::cout << " This Form was already signed " << std::endl;
  }
}

const std::string Form::getName(void) const { return this->_name; }

bool Form::hasSigned(void) const { return this->_signed; }

unsigned int Form::getGradeToSigned(void) const { return this->_gradeToSign; }

unsigned int Form::getGradeToExecute(void) const {
  return this->_gradeToExecute;
}

const char *Form::GradeTooLowException::what() const throw() {
  return "grade is too low for this form";
}

const char *Form::GradeTooHighException::what() const throw() {
  return "grade is too High for this form";
}
