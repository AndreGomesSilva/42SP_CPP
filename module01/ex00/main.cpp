#include "Zombie.hpp"

int main()
{
  Zombie *zombie = newZombie("Carl");
  zombie->announce();
  randomChump("Rick");
  delete zombie;
  return (0);
}
