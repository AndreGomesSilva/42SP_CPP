#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
  ClapTrap a("Clap");
  a.status();
  std::cout << "----------------" << std::endl;
  ScavTrap b("Scav");
  b.status();
  std::cout << "----------------" << std::endl;
  FragTrap c("Frag");
  c.status();
  std::cout << "----------------" << std::endl;
  FragTrap d;
  d = c;
  d.status();
  std::cout << "----------------" << std::endl;
  a.attack("Scav");
  b.guardGate();
  b.takeDamage(a.getAttackDamage());
  c.highFivesGuys();
  d.highFivesGuys();
  std::cout << "----------------" << std::endl;
  a.status();
  b.status();
  c.status();
  d.status();
  return 0;
}
