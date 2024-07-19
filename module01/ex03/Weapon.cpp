#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::~Weapon()
{
}

std::string const &Weapon::getType() const
{
  return (_type);
}

void    Weapon::setType(std::string type)
{
  _type = type;
}



