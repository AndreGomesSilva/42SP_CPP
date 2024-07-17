#include "Zombie.hpp"

int main()
{
  Zombie *zombie = newZombie("Carl");
  randomChump("Rick");
  delete zombie;
  return (0);
}
