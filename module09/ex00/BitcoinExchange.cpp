#include "BitcoinExchange.hpp"
#include <cstdio>
#include <exception>
#include <fstream>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <string>

Btc::Btc() : _dataFile("data.csv"), _db(NULL), _execFile("input.txt"){};

Btc::Btc(std::string const dataFile, std::string const execFile) : _dataFile(dataFile), _db(NULL), _execFile(execFile) {}

Btc::Btc(std::string const dataFile, std::map<std::string const, float> *db, std::string const execFile) : _dataFile(dataFile), _db(db), _execFile(execFile) {
  std::cout << "Constructor called" << std::endl;}

Btc::~Btc(){
  std::cout << "Destructor called" << std::endl;
}

bool Btc::initDB(){
  std::map<std::string const, float> db;
  try {
    this->setDB(&db); 
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
    return false;
  }
  return true;
}

static void printDB(std::map<std::string const, float> *db)
{
  std::cout << "------ DB ------" << std::endl; 
  for (std::map<std::string const, float>::iterator it = db->begin(); it != db->end(); ++it)
  {
    std::cout << "Key: " <<  it->first << " -- Value: " << it->second << std::endl;
  }
  std::cout << "------ -- ------" << std::endl; 
}

static float stringToFloat(const std::string &str)
{
  std::stringstream ss(str);
  float result;
  ss >> result;

  if (ss.fail())
  {
    throw std::invalid_argument("Error: problem with format of value");
  }

  return result;
}

void Btc::setDB(std::map<std::string const, float> *db){
  std::string key;
  std::string value;
  std::string line;

  std::ifstream file(_dataFile.c_str());
  std::getline(file, line);
  std::cout << line << std::endl;
  if (line != "date,exchange_rate")
      throw std::logic_error("Error: fail to fill the database, file corrupted");
  while (getline(file, line))
  {
   size_t pos = line.find(",");
   key = line.substr(0, pos);
   value = line.substr(pos + 1);
   (*db)[key] = stringToFloat(value);  
  }
  _db = db;
  printDB(_db);
  file.close();
}

static bool validateExtension(std::string input)
{
  std::string extension = input.substr(input.find(".") + 1);
  if (extension != "txt" && extension != "csv")
  {
    std::cerr << "Error: Ivalide file: " << input << std::endl;
    return false;
  }
  std::ifstream file(input.c_str());
  if (!file.is_open()) {
    std::cerr << "Error: Could not open file " << input << std::endl;
    return false;
  }
  file.close();
  return true;
}

bool Btc::validateFiles() {
  if (_dataFile.empty() || _execFile.empty())
    return false;
  if (!validateExtension(_dataFile) && !validateExtension(_execFile)) 
    return false;
  return true;
}
