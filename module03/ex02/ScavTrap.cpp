#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
  std::cout << "ScavTrap default constructor called" << std::endl;
  setHitPoints(100);
  setEnergyPoints(50);
  setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  std::cout << "ScavTrap name parameter constructor called" << std::endl;
  setHitPoints(100);
  setEnergyPoints(50);
  setAttackDamage(20);
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src) {
  std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
  setName(rhs.getName());
  setHitPoints(rhs.getHitPoints());
  setEnergyPoints(rhs.getEnergyPoints());
  setAttackDamage(rhs.getAttackDamage());
  return *this;
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode"
            << std::endl;
}

void ScavTrap::attack(std::string const &target) {
  if (getHitPoints() > 0 && getEnergyPoints() > 0) {
    std::cout << "ScavTrap " << getName() << " attacks " << target
              << ", causing " << getAttackDamage() << " points of damage!"
              << std::endl;
    setEnergyPoints(getEnergyPoints() - 1);
  } else {
    std::cout << "ScavTrap " << getName()
              << " is out of hit points or energy points!" << std::endl;
  }
}
