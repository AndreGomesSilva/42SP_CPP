#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap {
public:
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(ClapTrap const &src);
  ~ClapTrap();

  ClapTrap &operator=(ClapTrap const &rhs);
  void attack(std::string const &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void status(void) const;

  std::string getName() const;
  unsigned int getHitPoints() const;
  unsigned int getEnergyPoints() const;
  unsigned int getAttackDamage() const;

protected:
  void setName(std::string name);
  void setHitPoints(unsigned int amount);
  void setEnergyPoints(unsigned int amount);
  void setAttackDamage(unsigned int amount);

private:
  std::string _name;
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;
};

#endif // __CLAPTRAP_HPP__
