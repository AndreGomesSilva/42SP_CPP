#include "ClapTrap.hpp"

int main() {

  ClapTrap a("a");
  ClapTrap b("b");

  a.attack(b.getName());
  b.takeDamage(a.getAttackDamage());
  a.beRepaired(5);
  b.beRepaired(5);
}
