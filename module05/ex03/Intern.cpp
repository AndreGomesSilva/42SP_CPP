#include "Intern.hpp"

Intern::Intern() {
  std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &copy) { *this = copy; }

Intern &Intern::operator=(const Intern &copy) {
  (void)copy;
  return *this;
  std::cout << "Intern copy assignment operator called" << std::endl;
}

Intern::~Intern() { std::cout << "Intern destructor called" << std::endl; }

AForm *Intern::factoryShrubbery(std::string target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::factoryRobotomy(std::string target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::factoryPresidential(std::string target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target) {
  std::string names[3] = {"shrubbery request", "robotomy request",
                          "presidential pardon request"};
  AForm *(Intern::*forms[3])(std::string) = {&Intern::factoryShrubbery,
                                             &Intern::factoryRobotomy,
                                             &Intern::factoryPresidential};
  for (unsigned int i = 0; i < 3; i++) {
    if (names[i] == name) {
      std::cout << "Intern creates " << name << std::endl;
      return (this->*forms[i])(target);
    }
  }
  std::cout << "Intern can't create " << name << std::endl;
  return NULL;
}
