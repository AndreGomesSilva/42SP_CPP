#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ostream>

int main() {

  std::cout << std::endl;
  std::cout << "                  ______EX02______                      " << std::endl;
  //Create Bureaucrats
  std::cout << std::endl;
  std::cout << "-------Constructors-------" << std::endl;
  Bureaucrat b1("b1", 1);
  Bureaucrat b2("b2", 150);
  Bureaucrat b3("b3", 50);
  //Create Forms
  ShrubberyCreationForm f1("Work");
  ShrubberyCreationForm f2("Home");
  RobotomyRequestForm f3("Robotomy");
  PresidentialPardonForm f4("Marvin");
  RobotomyRequestForm f5("Robotomy");

  //Execute Forms
  std::cout << std::endl;
  std::cout << "-------Execute-------" << std::endl;
  b1.executeForm(f1);
  b2.executeForm(f2);
  b3.executeForm(f3);
  b1.executeForm(f4);
  b1.executeForm(f5);

  //Sign Forms
  std::cout << std::endl;
  std::cout << "-------Sign-------" << std::endl;
  b1.signForm(f1);
  b2.signForm(f2);
  b3.signForm(f3);
  b1.signForm(f4);
  b1.signForm(f5);

  //Execute Forms
  std::cout << std::endl;
  std::cout << "-------Execute-------" << std::endl;
  b1.executeForm(f1);
  b2.executeForm(f2);
  b3.executeForm(f3);
  b1.executeForm(f4);
  b1.executeForm(f5);

  //Execute Forms
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "-------Destructors-------" << std::endl;
  return (0);
}
