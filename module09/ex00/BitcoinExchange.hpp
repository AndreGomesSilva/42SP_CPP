#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
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
 std::map<std::string const, float>::iterator validateInputLine(std::string date, float value);
 bool initDB();
 void searchPrice(void);
 std::map<std::string const, float>::iterator getPrice(std::string const date);
 std::map<std::string const, float> *getDB(std::string const _dataFile) const;
  void setDB(std::map<std::string const, float> *db);

  class InvalidInputException : public std::exception {
      private:
        std::string _message;

      public:
        InvalidInputException(const std::string& message);
        virtual ~InvalidInputException() throw();
        virtual const char *what() const throw();
  };
};

#endif
