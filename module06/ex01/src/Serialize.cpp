#include "../include/Serialize.hpp"

uintptr_t Serialize::serialize(Data *ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serialize::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
}

Serialize::Serialize() {}

Serialize::Serialize(Serialize const &src) { (void)src; }

Serialize::~Serialize() {}

Serialize &Serialize::operator=(Serialize const &rhs) {
  (void)rhs;
  return *this;
}
