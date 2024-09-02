#include <fstream>
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2)
  {
      std::cerr << "Usage:  " << argv[0]  << " <filename>" << std::endl;
      return 1;
  }

  std::ifstream file(argv[1]);
  if (!file) {
      std::cerr << "Error: Could not open file " << argv[1] << std::endl;
      return 1;
  }

  std::cout << "------------" << std::endl;
  std::cout << std::endl;
  return 0;
}
