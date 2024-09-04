#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "iostream"
#include "map"
#include <map>

class Btc {
 private:
    std::map<std::string, float> db;

 public:
    Btc();
    Btc(const Btc &other);
    ~Btc();
};


#endif
