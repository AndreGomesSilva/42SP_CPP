#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <stdint.h>

struct Data {
  std::string s1;
  int i;
  std::string s2;
};

class Serialize {
private:
  Serialize();
  Serialize(Serialize const &src);
  ~Serialize();
  Serialize &operator=(Serialize const &rhs);

public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif
