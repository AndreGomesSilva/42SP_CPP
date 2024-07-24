#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
  class HumanA
{
  public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
    void attack();
  
  private:
    std::string _name;
    Weapon &_weapon;
};private:
    std::string _type;
  public:
    Weapon(std::string type);
    ~Weapon();
    void    setType(std::string type);
    std::string const &getType() const;
};

#endif //WEAPON_HPP
