#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
  std::cout << "Bureaucrat default constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade)
    : _name(name) {
  std::cout << "Bureaucrat " << name << " was created, with grade: " << grade
            << std::endl;
  if (grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  } else if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
  _grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy)
    : _name(copy._name), _grade(copy._grade) {
  std::cout << "Copy constructor called" << std::endl;
}
Bureaucrat::~Bureaucrat() {
  std::cout << "Destructor of Bureaucrat called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
  if (this != &copy)
    this->_grade = copy._grade;
  return *this;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &Bureaucrat) {
  os << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade()
     << ".";
  return os;
}

std::string Bureaucrat::getName(void) const { return this->_name; }

unsigned int Bureaucrat::getGrade(void) const { return this->_grade; }

void Bureaucrat::setGrade(unsigned int grade) {
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
  _grade = grade;
}

void Bureaucrat::incrementGrade(unsigned int level) {
  unsigned int grade;
  grade = this->getGrade();
  std::cout << "the grade of bureaucrat " << this->getName()
            << ", was increment " << level << " levels" << std ::endl;
  grade -= level;
  try {
    this->setGrade(grade);
  } catch (Bureaucrat::GradeTooHighException &e) {
    std::cerr << e.what() << std ::endl;
  }
}

void Bureaucrat::decrementGrade(unsigned int level) {
  unsigned int grade;
  grade = this->getGrade();
  std::cout << "the grade of bureaucrat " << this->getName()
            << ", was decrement " << level << " levels" << std ::endl;
  grade += level;
  try {
    this->setGrade(grade);
  } catch (Bureaucrat::GradeTooLowException &e) {
    std::cerr << e.what() << std::endl;
  } catch (Bureaucrat::GradeTooHighException &e) {
    std::cerr << e.what() << std::endl;
  }
}

void Bureaucrat::signForm(Form &form) {
  try {
    if (this->getGrade() < 1) {
      throw Bureaucrat::GradeTooHighException();
    } else if (this->getGrade() > 150) {
      throw Bureaucrat::GradeTooLowException();
    }
    form.beSigned(*this);
    if (form.hasSigned())
      std::cout << this->getName() << " signed " << form.getName() << std::endl;
  } catch (const std::exception &e) {
    std::cout << this->getName() << " couldn't sign " << form.getName()
              << " because " << e.what() << std::endl;
  } catch (...) {
    std::cout << this->getName() << " couldn't sign " << form.getName()
              << std::endl;
  }
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low!";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high!";
}
