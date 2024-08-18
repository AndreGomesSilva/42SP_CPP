#include "../include/Serialize.hpp"
#include <iostream>

int main(void) {
  Data data = {"hello", 42, "world"};
  std::cout << "s1: " << data.s1 << " - value: " << data.i
            << " - s2: " << data.s2 << std::endl;
  uintptr_t seriData = Serialize::serialize(&data);
  std::cout << "s1: " << data.s1 << " - value: " << data.i
            << " - s2: " << data.s2 << std::endl;
  std::cout << "Data serialize: " << seriData << std::endl;
  Data *deseData = Serialize::deserialize(seriData);
  std::cout << "s1: " << deseData->s1 << " - value: " << deseData->i
            << " - s2: " << deseData->s2 << std::endl;
  return 0;
}
