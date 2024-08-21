#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class Bureaucrat;

class Form {
private:
  const std::string _name;
  bool _signed;
  const unsigned int _gradeToSign;
  const unsigned int _gradeToExecute;

public:
  Form();
  Form(std::string name, unsigned int gradeToSigned,
       unsigned int gradeToExecute);
  ~Form();
  Form(const Form &copy);
  Form &operator=(const Form &copy);

  void beSigned(Bureaucrat &Bureaucrat);

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
};

std::ostream &operator<<(std::ostream &os, Form const &Form);
#endif // !FORM_HPP
