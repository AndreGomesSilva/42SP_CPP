#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"


int main()
{
  Weapon club = Weapon("crude spiked");
  HumanA bob("Bob", club);
  bob.attack();
  club.setType("some other type of club");
  bob.attack();
  HumanB jim("Jim");
  jim.setWeapon(club);
  jim.attack();
  club.setType("some other type of club");
  jim.attack();
  return (0);
}
