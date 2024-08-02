#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap " << _name << " is created!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap " << _name << " is created!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
    : _name(src._name), _hitPoints(src._hitPoints),
      _energyPoints(src._energyPoints), _attackDamage(src._attackDamage) {
  std::cout << "ClapTrap " << _name << " is created!" << std::endl;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << _name << " is destroyed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
  _name = rhs._name;
  _hitPoints = rhs._hitPoints;
  _energyPoints = rhs._energyPoints;
  _attackDamage = rhs._attackDamage;
  return *this;
}

void ClapTrap::attack(std::string const &target) {
  if (_hitPoints > 0 && _energyPoints > 0) {
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
              << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
  } else {
    std::cout << "ClapTrap " << _name
              << " is out of hit points or energy points!" << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hitPoints > 0) {
    std::cout << "ClapTrap " << _name << " takes " << amount
              << " points of damage!" << std::endl;
    _hitPoints -= amount;
  } else {
    std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_hitPoints > 0 && _energyPoints > 0) {
    std::cout << "ClapTrap " << _name << " is repaired for " << amount
              << " hit points!" << std::endl;
    _hitPoints += amount;
    _energyPoints--;
  } else {
    std::cout << "ClapTrap " << _name
              << " is out of hit points or energy points!" << std::endl;
  }
}

std::string ClapTrap::getName() const { return _name; }

unsigned int ClapTrap::getHitPoints() const { return _hitPoints; }

unsigned int ClapTrap::getEnergyPoints() const { return _energyPoints; }

unsigned int ClapTrap::getAttackDamage() const { return _attackDamage; }
