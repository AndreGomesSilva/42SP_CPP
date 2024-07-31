#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src) {}

ScavTrap::~ScavTrap() {}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
  _name = rhs._name;
  _hitPoints = rhs._hitPoints;
  _energyPoints = rhs._energyPoints;
  _attackDamage = rhs._attackDamage;
  return *this;
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << _name << " is now in Gate keeper mode"
            << std::endl;
}

void ScavTrap::attack(std::string const &target) {
  if (_hitPoints > 0 && _energyPoints > 0) {
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
              << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
  } else {
    std::cout << "ScavTrap " << _name
              << " is out of hit points or energy points!" << std::endl;
  }
}
