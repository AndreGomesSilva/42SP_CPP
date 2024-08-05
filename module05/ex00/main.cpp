#include "Bureaucrat.hpp"
#include <ostream>

int main() {
  try {
    Bureaucrat b1("B1", 200);

  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    Bureaucrat b3("B2", 75); // This should not throw any exceptions
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cerr << e.what() << std::endl;
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    Bureaucrat b3("B3", 0);
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cerr << e.what() << std::endl;
  }
  return (0);
}
