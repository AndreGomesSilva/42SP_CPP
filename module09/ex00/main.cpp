#include <fstream>
#include <iostream>
#include <string>

int validateFile(std::string input) {
  if (input.empty())
    return 1;
  std::string extension = input.substr(input.find(".") + 1);
  if (extension != "txt" || extension != "csv")
    return 1;
  std::ifstream file(input);
  if (!file) {
    std::cerr << "Error: Could not open file " << input << std::endl;
    return 1;
  }
  return 0;
}


int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage:  " << argv[0] << " <filename>" << std::endl;
    return 1;
  }
  std::string input = argv[1];
  std::string dataFile = "data.csv";
  if (!validateFile(input) && !validateFile(dataFile))
  {
    std::cerr << "Invalid File" << std::endl;
    return 1;
  }
  return 0;
}
