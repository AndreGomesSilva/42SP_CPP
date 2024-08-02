#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
  setHitPoints(100);
  setEnergyPoints(100);
  setAttackDamage(30);
  std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  setHitPoints(100);
  setEnergyPoints(100);
  setAttackDamage(30);
  std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src) {
  std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
  if (this != &rhs) {
    ClapTrap::operator=(rhs);
  }
  return *this;
}

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap " << getName() << " is asking for a high five!"
            << std::endl;
}
