#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__

#include <iostream>

class Zombie 
{
  public:
    Zombie(std::string name);
    ~Zombie(void);

    void announce(void) const;

  private:
    std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif // !__ZOMBIE_H__
