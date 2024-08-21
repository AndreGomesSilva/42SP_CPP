#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm {
private:
  const std::string _name;
  bool _signed;
  const unsigned int _gradeToSign;
  const unsigned int _gradeToExecute;

public:
  AForm();
  AForm(std::string name, unsigned int gradeToSigned,
        unsigned int gradeToExecute);
  virtual ~AForm();
  AForm(const AForm &copy);
  AForm &operator=(const AForm &copy);

  //pure virtual method
  virtual void beSigned(Bureaucrat &Bureaucrat);
  void execute(Bureaucrat const &executor) const;
  virtual void action() const = 0;

  const std::string getName(void) const;
  bool hasSigned(void) const;
  unsigned int getGradeToSigned(void) const;
  unsigned int getGradeToExecute(void) const;

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooHighException : public std::exception {
    const char *what() const throw();
  };
  class FormNotSignedException : public std::exception {
    const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, AForm const &Form);
#endif // !AFORM_HPP
