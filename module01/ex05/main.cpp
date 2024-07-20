#include "Harl.hpp"

int main(int argc, char **argv)
{
  if (argc == 2)
  {
    Harl harl;
    std::string level = argv[1];
    harl.complain(level);
  }
  else
    std::cout << "Wrong number of arguments" << std::endl;
  
  return (0);
}
