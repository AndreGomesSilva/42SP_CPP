#include "Harl.hpp"

int select_level(std::string level) {
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  for (int i = 0; i < 4; i++) {
    if (level == levels[i])
      return i;
  }
  return -1;
}

int main(int argc, char **argv) {
  if (argc == 2) {
    Harl Harl;
    int level = select_level(argv[1]);
    switch (level) {
    case 0:
      Harl.complain("DEBUG");
    case 1:
      Harl.complain("INFO");
    case 2:
      Harl.complain("WARNING");
    case 3:
      Harl.complain("ERROR");
      break;
    default:
      std::cout << "[ Proably complaining about insignificant problems ]"
                << std::endl;
      break;
    }
  } else
    std::cout << "Wrong number of arguments" << std::endl;

  return (0);
}
