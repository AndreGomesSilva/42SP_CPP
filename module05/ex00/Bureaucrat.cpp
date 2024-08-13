#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
  std::cout << "Bureaucrat default constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade)
    : _name(name) {
  std::cout << "Bureaucrat " << name << " was created, with grade: " << grade
            << std::endl;
  if (grade < 1) {
    throw GradeTooHighException();
  } else if (grade > 150)
    throw GradeTooLowException();
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

std::string Bureaucrat::getName(void) const { return this->_name; }

unsigned int Bureaucrat::getGrade(void) const { return this->_grade; }

void Bureaucrat::setGrade(unsigned int grade) {
  if (grade < 1)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();
  _grade = grade;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade iss too low!";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade iss too high!";
}
