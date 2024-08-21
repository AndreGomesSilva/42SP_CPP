#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("Home") {
  std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
  std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) :
    AForm("ShrubberyCreationForm", 145, 137), _target(copy._target)
{  
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &copy) {
  if (this != &copy)
  {
    std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
    _target = copy._target;
  }
  return *this;
} 

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "ShrubberyCreationForm destructor called" << *this << std::endl;
}

void ShrubberyCreationForm::createTree(std::string target) const {
  std::string filename = target + "_shrubbery";
  std::ofstream outfile(filename.c_str());
  if (!outfile) {
    std::cerr << "Error: cannot open file " << filename << std::endl;
    return;
  }
        outfile << "    ccee88oo\n"
                << "  C8O8O8Q8PoOb o8oo\n"
                << " dOB69QO8PdUOpugoO9bD\n"
                << "CgggbU8OU qOp qOdoUOdcb\n"
                << "    6OuU  /p u gcoUodpP\n"
                << "      \\\\\\//  /douUP\n"
                << "        \\\\////\n"
                << "         |||/\\\n"
                << "         |||\\/\n"
                << "         |||||\n"
                << "   .....//||||\\....\n";
  outfile.close();
  std::cout << "File " << filename << " created" << std::endl;
}

void ShrubberyCreationForm::destroyTree(std::string target) const {
  std::string filename = target + "_shrubbery";
  std::remove(filename.c_str());
  std::cout << "File " << filename << " deleted" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const {
  return _target;
}

void ShrubberyCreationForm::action() const {
  createTree(_target);
}

