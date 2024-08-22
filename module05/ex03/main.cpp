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
  AForm *rrf = NULL;
  std::cout << std::endl;

  std::cout << "-------Functions-------" << std::endl;
  rrf = someRandomIntern.makeForm("robotomy request", "Bender");
  std::cout << std::endl;

  std::cout << *rrf << std::endl;
  std::cout << "-------Destructors-------" << std::endl;
  delete rrf;
  return (0);
}
