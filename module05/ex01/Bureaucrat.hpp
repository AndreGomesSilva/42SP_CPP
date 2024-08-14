#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "iostream"
#include <exception>
#include <string>

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

  void incrementGrade(unsigned int level = 1);
  void decrementGrade(unsigned int level = 1);

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

#endif // BUREAUCRAT_HPP