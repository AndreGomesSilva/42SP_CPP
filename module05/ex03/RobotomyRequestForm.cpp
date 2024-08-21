#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
  : AForm("RobotomyRequestForm", 72, 45), _target(target) {
  std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy)
  : AForm(copy), _target(copy._target) {
  std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &copy) {
  if (this != &copy) {
    _target = copy._target;
  }
  return *this;
}

void RobotomyRequestForm::robotomyze(std::string target) const {
  std::cout << "Bzzzzzzzzzzzzz..." << std::endl;
  srand(time(NULL));
  if (rand() % 2)
    std::cout << target << " has been robotomized successfully" << std::endl;
  else
    std::cout << "Robotomy failed" << std::endl;
}

void RobotomyRequestForm::action() const {
  robotomyze(_target);
}
