#include "Harl.hpp"

void Harl::debug(void) {
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout
      << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
      << std::endl;
}

void Harl::info(void) {
  std::cout << "[ INFO ]" << std::endl;
  std::cout
      << "I cannot believe adding extra bacon cost more money. You didn't put "
         "enough bacon in my burger! If you did, I wouldn't be asking for more!"
      << std::endl;
}

void Harl::warning(void) {
  std::cout << "[ WARNING ]" << std::endl;
  std::cout
      << "I think I deserve to have some extra bacon for free. I've been "
         "coming here for years and you just started working here last month."
      << std::endl;
}

void Harl::error(void) {
  std::cout << "[ ERROR ]" << std::endl;
  std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
}

void Harl::complain(std::string level) {
  void (Harl::*complains[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning,
                                      &Harl::error};
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  for (int i = 0; i < 4; i++) {
    if (level == levels[i])
      (this->*(complains[i]))();
  }
}
