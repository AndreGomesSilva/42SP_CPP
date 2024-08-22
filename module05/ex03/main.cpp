#include "AForm.hpp"
#include "Intern.hpp"
#include <ostream>

int main() {
  std::cout << std::endl;
  std::cout << "                  ______EX03______                      "
            << std::endl;
  std::cout << std::endl;
  std::cout << "-------Constructors-------" << std::endl;
  Intern someRandomIntern;
  AForm *robotomy = NULL;
  AForm *shrubbery = NULL;
  AForm *presidentialPardon = NULL;

  std::cout << "-------False Request-------" << std::endl;
  std::cout << std::endl;
  AForm *falseRequest = NULL;
  std::cout << std::endl;

  std::cout << "-------Forms-------" << std::endl;
  robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
  shrubbery =
      someRandomIntern.makeForm("presidential pardon request", "Marvin");
  presidentialPardon = someRandomIntern.makeForm("shrubbery request", "Home");
  falseRequest = someRandomIntern.makeForm("false request", "Hacker123");
  std::cout << std::endl;

  if (robotomy != NULL)
    std::cout << *robotomy << std::endl;
  if (shrubbery != NULL)
    std::cout << *shrubbery << std::endl;
  if (presidentialPardon != NULL)
    std::cout << *presidentialPardon << std::endl;
  if (falseRequest != NULL) {
    std::cout << *falseRequest << std::endl;
    delete falseRequest;
  }
  std::cout << "-------Destructors-------" << std::endl;
  delete robotomy;
  delete shrubbery;
  delete presidentialPardon;
  return (0);
}
