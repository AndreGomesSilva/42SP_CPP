#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class Form {
private:
  const std::string _name;
  bool _signed;
  const unsigned int _gradeToSigned;
  const unsigned int _gradeToExecute;

public:
  Form();
  ~Form();
  Form(const Form &copy);
  Form &operator=(const Form &copy);

  void beSigned(Bureaucrat &Bureaucrat);
  void setGradeToSigned(unsigned int grade);
  void setGradeToExecute(unsigned int grade);

  const std::string getName(void) const;
  bool hasSigned(void) const;
  const unsigned int getGradeToSigned(void);
  const unsigned int getGradeToExecute(void);

  class GradeTooLowException : std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooHighException : std::exception {
    const char *what() const throw();
  };
};
#endif // !FORM_HPP
