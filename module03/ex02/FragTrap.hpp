#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {
public:
  FragTrap();
  FragTrap(std::string name);
  FragTrap(FragTrap const &src);
  ~FragTrap();
  FragTrap &operator=(FragTrap const &rhs);
  void highFivesGuys();
};

#endif // __FLAGTRAP_HPP__
