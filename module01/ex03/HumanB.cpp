#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB() {}
HumanB::HumanB(std::string name) : _name(name) {}
HumanB::~HumanB() {}

void HumanB::attack()
{
  std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
  _weapon = &weapon;
}
