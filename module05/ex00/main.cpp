#include "Bureaucrat.hpp"
#include <ostream>

int main() {
  std::cout << std::endl;
  std::cout << "                  ______EX00______                      "
            << std::endl;
  std::cout << std::endl;
  try {
    std::cout << "Trying to create a new bureaucrat with grade of 200"
              << std::endl;
    Bureaucrat b1("B1", 200);
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << "--------------" << std::endl;

  try {
    std::cout << "Trying to create a new bureaucrat with grade of 75"
              << std::endl;
    Bureaucrat b2("B2", 75);
    std::cout << b2 << std::endl;

    std::cout << "Trying to increment " << b2.getName() << " grade in 1"
              << std::endl;
    b2.incrementGrade();
    std::cout << b2 << std::endl;

    std::cout << "Trying to decrement " << b2.getName() << " grade in 5"
              << std::endl;
    b2.decrementGrade(5);
    std::cout << b2 << std::endl;
    std::cout << "Trying to decrement " << b2.getName() << " grade in 200"
              << std::endl;
    b2.decrementGrade(200);
    std::cout << b2 << std::endl;

  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cerr << e.what() << std::endl;
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "--------------" << std::endl;

  try {
    std::cout << "Trying to create a new bureaucrat with grade of 0"
              << std::endl;
    Bureaucrat b3("B3", 0);
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << "--------------" << std::endl;

  return (0);
}
