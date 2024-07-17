#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
  Zombie *zombie = new Zombie(name);
  std::cout << "Zombie " << name << " created" << std::endl;
  return (zombie);
}
