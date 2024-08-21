#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <string>

class AForm;

class Bureaucrat {
private:
  const std::string _name;
  unsigned int _grade;

public:
  Bureaucrat();
  Bureaucrat(const std::string &name, unsigned int grade);
  Bureaucrat(const Bureaucrat &copy);
  ~Bureaucrat();

  Bureaucrat &operator=(const Bureaucrat &copy);

  std::string getName(void) const;
  unsigned int getGrade(void) const;
  void setGrade(unsigned int);
  void signForm(AForm &form);

  void incrementGrade(unsigned int level = 1);
  void decrementGrade(unsigned int level = 1);

  void executeForm(AForm const &form);

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &Bureaucrat);

#endif // BUREAUCRAT_HPP
