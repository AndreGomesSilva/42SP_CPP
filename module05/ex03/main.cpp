#include "Intern.hpp"
#include "AForm.hpp"
#include <ostream>

int main() {

  std::cout << std::endl;
  std::cout << "                  ______EX03______                      " << std::endl;
  std::cout << std::endl;
  std::cout << "-------Constructors-------" << std::endl;
  Intern someRandomIntern;
  AForm *rrf;
  std::cout << std::endl;

  std::cout << "-------Functions-------" << std::endl;
  someRandomIntern.makeForm("robotomy request", "Bender");
  std::cout << std::endl;
  
  std::cout << rrf << std::endl;
  std::cout << "-------Destructors-------" << std::endl;
  return (0);
}
