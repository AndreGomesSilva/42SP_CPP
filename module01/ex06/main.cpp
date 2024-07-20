#include "Harl.hpp"
#include <cstdlib>

int main(int argc, char **argv)
{
  if (argc == 2)
  {
    int level;
    Harl Harl;
    for (int i = 0; argv[1][i]; i++)
    {
      level += argv[1][i] - '0';
    }
    switch (level)
    {
      case 119:
        Harl.complain("DEBUG");
        break;
      case 108:
        Harl.complain("INFO");
        break;
      case 198:
        Harl.complain("WARNING");
        break;
      case 154:
        Harl.complain("ERROR");
        break;
      default:
        std::cout << "[ Proably complaining about insignificant problems ]" << std::endl;
        break;
    }
  }
  else
    std::cout << "Wrong number of arguments" << std::endl;
  
  return (0);
}
