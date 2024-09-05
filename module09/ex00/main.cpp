#include <fstream>
#include <iostream>
#include <string>
#include "BitcoinExchange.hpp"


int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage:  " << argv[0] << " <filename>" << std::endl;
    return 1;
  }
  std::string const input = argv[1];
  std::string const dataFile = "data.csv";
  Btc bitcoin(dataFile, input); 
  if (!bitcoin.validateFiles())
  {
    std::cerr << "Invalid File" << std::endl;
    return 1;
  }
  bitcoin.initDB();
  std::cout << "Ok " << std::endl; return 0;
}
