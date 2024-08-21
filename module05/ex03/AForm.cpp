#include "AForm.hpp"

AForm::AForm()
    : _name("default"), _signed(false), _gradeToSign(150),
      _gradeToExecute(150) {
  std::cout << "default " << *this << " was created " << std::endl;
}

AForm::AForm(std::string name, unsigned int gradeToSign,
             unsigned int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1)
    throw(AForm::GradeTooHighException());
  else if (gradeToSign > 150 || gradeToExecute > 150)
    throw(AForm::GradeTooLowException());
  else {
    std::cout << *this << " was created " << std::endl;
  };
}

AForm::AForm(const AForm &copy)
    : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign),
      _gradeToExecute(copy._gradeToExecute) {
  std::cout << *this << " was copied " << std::endl;
};

AForm::~AForm() {
  std::cout << *this << " was deleted " << std::endl;
};

AForm &AForm::operator=(const AForm &copy) {
  if (this != &copy) {
    _signed = copy._signed;
    std::cout << *this << " was copied " << std::endl;
  }
  return *this;
}

std::ostream &operator<<(std::ostream &os, AForm const &Form) {
  std::string sign = "not sign";

  if (Form.hasSigned()) {
    sign = "signed";
  }
  os << "Formulario: " << Form.getName() << ", is: " << sign
     << ", grade to sign: " << Form.getGradeToSigned()
     << ", grade to execute: " << Form.getGradeToExecute() << ".";
  return os;
}

void AForm::beSigned(Bureaucrat &Bureaucrat) {
  unsigned int bureaucratGrade = Bureaucrat.getGrade();
  if (this->_signed == false) {
    {
      if (bureaucratGrade > this->getGradeToSigned()) {
        throw(AForm::GradeTooLowException());
      } else
        _signed = true;
    }
  } else {
    std::cout << " This Form was already signed " << std::endl;
  }
}

const std::string AForm::getName(void) const { return this->_name; }

bool AForm::hasSigned(void) const { return this->_signed; }

unsigned int AForm::getGradeToSigned(void) const { return this->_gradeToSign; }

unsigned int AForm::getGradeToExecute(void) const {
  return this->_gradeToExecute;
}

void AForm::execute(Bureaucrat const &executor) const {
  if (this->hasSigned() == false) {
    throw(AForm::FormNotSignedException());
  }
  if (executor.getGrade() > this->getGradeToExecute()) {
    throw(AForm::GradeTooLowException());
  }
  this->action();
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "grade is too low for this form";
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "grade is too High for this form";
}

const char *AForm::FormNotSignedException::what() const throw() {
  return "form is not signed";
}
