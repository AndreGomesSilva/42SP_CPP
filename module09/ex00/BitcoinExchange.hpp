#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "iostream"
#include <fstream>
#include <map>

class Btc {
 private:
  std::string const _dataFile;
  std::map<std::string const, float> *_db;
  std::string const _execFile;

 public:
    Btc();
    Btc(std::string const dataFile, std::string const execFile);
    Btc(std::string const dataFile, std::map<std::string const, float> *db, std::string const execFile);
    Btc(const Btc &other);
    ~Btc();


 bool validateFiles();
 bool initDB();
 std::map<std::string const, float> *getDB(std::string const _dataFile) const;
  void setDB(std::map<std::string const, float> *db);
};




#endif
