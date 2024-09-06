#include "BitcoinExchange.hpp"
#include <cstdio>
#include <iostream>
#include <stdexcept>

Btc::Btc() : _dataFile("data.csv"), _db(NULL), _execFile("input.txt"){};

Btc::Btc(std::string const dataFile, std::string const execFile) : _dataFile(dataFile), _db(NULL), _execFile(execFile) {}

Btc::Btc(std::string const dataFile, std::map<std::string const, float> *db, std::string const execFile) : _dataFile(dataFile), _db(db), _execFile(execFile) {
  std::cout << "Constructor called" << std::endl;}

Btc::~Btc(){
  std::cout << "Destructor called" << std::endl;
  delete _db;
}

static void printDB(std::map<std::string const, float> *db)
{
  std::cout << "------ DB ------" << std::endl; 
  for (std::map<std::string const, float>::iterator it = db->begin(); it != db->end(); ++it)
  {
    std::cout << "Key: " << std::fixed << std::setprecision(2) <<  it->first << " -- Value: " << it->second << std::endl;
  }
  std::cout << "------ -- ------" << std::endl; 
}

bool Btc::initDB(){
  _db = new std::map<std::string const, float>;
  try {
    this->setDB(_db); 
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
    return false;
  }
  printDB(_db);
  return true;
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

std::map<std::string const, float>::iterator Btc::getPrice(std::string const date) {
  if (date < _db->begin()->first)
    return _db->end();
  std::map<std::string const, float>::iterator it = _db->lower_bound(date);
  if (it->first != date)
    --it;
  if (it == _db->end())
  {
    throw std::logic_error("Error: Invalid date");
  }
  return it;
}

void Btc::searchPrice() {
  std::map<std::string const, float>::iterator it;
  std::string inputLine;
  std::string inputDate;
  float inputValue;
  size_t pos = 0;

  std::fstream file(_execFile.c_str());
  if (!file.is_open())
  {
      throw std::logic_error("Error: fail to open input file");
  }
  getline(file, inputLine);
  if (inputLine != "date | value")
  {
      file.close();
      throw std::logic_error("Error: fail to search price, input fail corrupted");
  }
  while (getline(file, inputLine))
  {
    pos = inputLine.find("|");
    inputDate = inputLine.substr(0, pos);
    inputValue = stringToFloat(inputLine.substr(pos + 1));
    if (pos == std::string::npos)
    {
      std::cout << "Error: bad input => " << inputLine << std::endl;
      continue;
    }
    if (inputValue <= 0)
    {
      std::cout << "Error: not a positive number." << std::endl;
      continue;
    }
    if (inputValue > 1000)
    {
      std::cout << "Error: too large a number." << std::endl;
      continue;
    }
    it = getPrice(inputDate); 
    if (it == _db->end())
    {
      std::cout << "Error: bad input => " << inputDate << std::endl;
      continue;
    }
    std::cout << inputDate << " => " << std::fixed << std::setprecision(0) << inputValue << " = " ;
    std::cout << std::fixed << std::setprecision(2) << inputValue * it->second << std::endl;
  }
  file.close();
}

void Btc::setDB(std::map<std::string const, float> *db){
  std::string key;
  std::string value;
  std::string line;

  std::ifstream file(_dataFile.c_str());
  std::getline(file, line);
  std::cout << line << std::endl;
  if (line != "date,exchange_rate")
  {
      file.close();
      throw std::logic_error("Error: fail to fill the database, file corrupted");
  }
  while (getline(file, line))
  {
   size_t pos = line.find(",");
   key = line.substr(0, pos);
   value = line.substr(pos + 1);
   (*db)[key] = stringToFloat(value);  
  }
  _db = db;
  if (_db->empty()){
    file.close();
    throw std::logic_error("Error: Could not fill the database");
  }
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
