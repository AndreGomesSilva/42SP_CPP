#include "BitcoinExchange.hpp"

Btc::Btc() : _dataFile("data.csv"), _db(NULL), _execFile("input.txt"){};

Btc::Btc(std::string const dataFile, std::string const execFile)
    : _dataFile(dataFile), _db(NULL), _execFile(execFile) {}

Btc::Btc(std::string const dataFile, std::map<std::string const, float> *db,
         std::string const execFile)
    : _dataFile(dataFile), _db(db), _execFile(execFile) {
  std::cout << "Constructor called" << std::endl;
}

Btc::~Btc() {
  delete _db;
}

bool Btc::initDB() {
  _db = new std::map<std::string const, float>;
  try {
    this->setDB(_db);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
    return false;
  }
  return true;
}

static float stringToFloat(const std::string &str) {
  std::stringstream ss(str);
  float result;
  ss >> result;
  if (ss.fail())
    throw std::exception();
  return result;
}

std::map<std::string const, float>::iterator
Btc::getPrice(std::string const date) {
  if (date < _db->begin()->first)
    throw Btc::InvalidInputException("Error: not a valid date => " + date);
  std::map<std::string const, float>::iterator it = _db->lower_bound(date);
  if (it->first != date)
    --it;
  return it;
}

void Btc::searchPrice() {
  std::map<std::string const, float>::iterator it;
  std::string inputLine;
  std::string date;
  float value = 0;
  size_t pos = 0;

  std::ifstream file(_execFile.c_str());
  if (!file.is_open()) {
    throw std::logic_error("Error: fail to open input file");
  }
  getline(file, inputLine);
  if (inputLine != "date | value") {
    std::cout << "Error: bad formated hearder inputFile" << std::endl;
    ;
  }
  while (getline(file, inputLine)) {
    try {
      pos = inputLine.find("|");
      date = inputLine.substr(0, pos);
      if (pos == std::string::npos)
        throw Btc::InvalidInputException("Error: bad input => " + date);
      try {
        value = stringToFloat(inputLine.substr(pos + 1));
      } catch (std::exception &e) {
        throw Btc::InvalidInputException("Error: bad input => " + date);
      }
      it = validateInputLine(date, value);
      if (it != _db->end())
        std::cout << date << "=> " << value << " = " << value * it->second
                  << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  file.close();
}

void Btc::setDB(std::map<std::string const, float> *db) {
  std::string key;
  std::string value;
  std::string line;

  std::ifstream file(_dataFile.c_str());
  std::getline(file, line);
  if (line != "date,exchange_rate") {
    file.close();
    throw std::logic_error("Error: fail to fill the database, file corrupted");
  }
  while (getline(file, line)) {
    size_t pos = line.find(",");
    key = line.substr(0, pos);
    value = line.substr(pos + 1);
    (*db)[key] = stringToFloat(value);
  }
  _db = db;
  if (_db->empty()) {
    file.close();
    throw std::logic_error("Error: Could not fill the database");
  }
  file.close();
}

static bool isLeapYear(int year) {
  return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

static bool validateDate(std::string &date) {
  if (date.empty())
    return false;
  int day, month, year;
  char delimiter1, delimiter2, space;
  std::stringstream ss(date);
  ss >> year >> delimiter1 >> month >> delimiter2 >> day;
  if (delimiter1 != '-' || delimiter2 != '-')
    return false;
  if (ss >> space) {
    if (space != ' ') {
      return false;
    }
    if (ss >> space) {
      return false;
    }
  }
  if (year < 2009 || year > 2024)
    return false;
  if (month < 1 || month > 12)
    return false;
  if (day < 1 || day > 31)
    return false;
  if (month == 2) {
    if (isLeapYear(year)) {
      if (day > 29) {
        return false;
      }
    } else {
      if (day > 28) {
        return false;
      }
    }
  }
  if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    return false;
  return true;
}

std::map<std::string const, float>::iterator
Btc::validateInputLine(std::string date, float value) {
  std::map<std::string const, float>::iterator it;
  if (value < 0)
    throw Btc::InvalidInputException("Error: not a positive number.");
  if (value > 1000)
    throw Btc::InvalidInputException("Error: too large a number.");
  if (!validateDate(date))
    throw Btc::InvalidInputException("Error: bad input date => " + date);
  it = getPrice(date);
  if (it == _db->end())
    throw Btc::InvalidInputException("Error: bad input => " + date);
  return it;
}

static bool validateExtension(std::string input) {
  std::string extension = input.substr(input.find(".") + 1);
  if (extension != "txt" && extension != "csv") {
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

Btc::InvalidInputException::InvalidInputException(const std::string &message)
    : _message(message) {}

Btc::InvalidInputException::~InvalidInputException() throw() {}

const char *Btc::InvalidInputException::what() const throw() {
  return this->_message.c_str();
}
