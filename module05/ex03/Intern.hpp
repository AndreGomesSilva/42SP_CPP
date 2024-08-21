#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
  private:
   AForm *factoryShrubbery(std::string target);
   AForm *factoryRobotomy(std::string target);
   AForm *factoryPresidential(std::string target);

  public:
    Intern();
    Intern(const Intern &copy);
    ~Intern();
    Intern &operator=(const Intern &copy);
    AForm *makeForm(std::string name, std::string target);
};

#endif
