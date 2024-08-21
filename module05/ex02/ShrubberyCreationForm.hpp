#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include "AForm.hpp"
#include "iostream"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
  std::string _target;
  void createTree(std::string target) const;
  void destroyTree(std::string target) const;
  void action() const;

public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(ShrubberyCreationForm &copy);
  ~ShrubberyCreationForm();

  ShrubberyCreationForm &operator=(ShrubberyCreationForm &copy);
  std::string getTarget() const;
};

#endif
