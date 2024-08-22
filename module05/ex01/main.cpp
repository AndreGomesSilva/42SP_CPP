#include "Bureaucrat.hpp"
#include <exception>
#include <ostream>

int main() {
  // Create Bureaicrats
  std::cout << std::endl;
  std::cout << "                  ______EX01______                      "
            << std::endl;
  std::cout << std::endl;
  try {
    std::cout << std::endl;
    std::cout << "------------------" << std ::endl;
    std::cout << std::endl;

    Bureaucrat bureaucrat01("b1", 23);
    Bureaucrat bureaucrat02("b2", 100);

    std::cout << std::endl;
    std::cout << "------------------" << std ::endl;
    std::cout << std::endl;

    // Create Forms
    Form form01("f1", 30, 100);
    Form form02(form01);
    Form form03("f3", 2, 100);

    std::cout << std::endl;
    std::cout << "------------------" << std ::endl;
    std::cout << std::endl;

    // sign forms
    std::cout << bureaucrat01 << std::endl;
    std::cout << form01 << std::endl;
    bureaucrat01.signForm(form01);
    std::cout << form01 << std::endl;

    std::cout << std::endl;
    std::cout << "------------------" << std ::endl;
    std::cout << std::endl;

    std::cout << form03 << std::endl;
    bureaucrat01.signForm(form03);
    std::cout << form03 << std::endl;

    std::cout << std::endl;
    std::cout << "------------------" << std ::endl;
    std::cout << std::endl;

  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  std::cout << "------------------" << std ::endl;
  std::cout << std::endl;

  return (0);
}
