#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class Bureaucrat;

class RobotomyRequestForm : public AForm {
private:
  std::string _target;
  void robotomyze(std::string target) const;
  void action() const;

public:
  RobotomyRequestForm();
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(RobotomyRequestForm &copy);
  ~RobotomyRequestForm();
  RobotomyRequestForm &operator=(RobotomyRequestForm &copy);
  std::string getTarget() const;
  int getGradeExecute() const;
};

#endif
