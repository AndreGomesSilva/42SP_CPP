#include "Bureaucrat.hpp"
#include <ostream>

int main() {
  try {
    Bureaucrat b1("B1", 200);

  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "--------------" << std::endl;

  try {
    Bureaucrat b2("B2", 75);
    std::cout << "The bureaucrat " << b2.getName() << " currently is a grade "
              << b2.getGrade() << std::endl;
    b2.incrementGrade();
    std::cout << "The bureaucrat " << b2.getName() << " currently is a grade "
              << b2.getGrade() << std::endl;
    b2.decrementGrade(5);
    std::cout << "The bureaucrat " << b2.getName() << " currently is a grade "
              << b2.getGrade() << std::endl;
    b2.decrementGrade(200);
    std::cout << "The bureaucrat " << b2.getName() << " currently is a grade "
              << b2.getGrade() << std::endl;

  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cerr << e.what() << std::endl;
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "--------------" << std::endl;

  try {
    Bureaucrat b3("B3", 0);
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << "--------------" << std::endl;

  return (0);
}
