#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
private:
  std::string _target;
  void action() const;
  void pardon() const;

public:
  PresidentialPardonForm();
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &copy);
  ~PresidentialPardonForm();
  PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
};

#endif
