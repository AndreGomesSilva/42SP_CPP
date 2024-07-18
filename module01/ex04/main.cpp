#include "Replace.hpp"

int printError(std::string const &str)
{
  std::cerr << "Error: " << str << std::endl;
  return (ERROR);
}

int main(int argc, char **argv)
{
  if (argc != 4)
    return (printError("Wrong number of arguments"));

  std::string line;
  std::string sourceFile;
  std::string destFile;
  std::string s1;
  std::string s2;

  sourceFile = argv[1];
  s1 = argv[2];
  s2 = argv[3];
  
  if (s1.empty() || s2.empty())
    return (printError("Empty string"));
  if (sourceFile.empty())
    return (printError("Empty file name"));
  
  std::ifstream srcFile(sourceFile.c_str());
  if (!srcFile.is_open())
    return (printError("Can't open file"));

  destFile = replaceExtension(sourceFile, ".replace");

  std::ofstream destFile2(destFile.c_str());
  if (!destFile2.is_open())
    return (printError("Can't open file"));

  while (std::getline(srcFile, line))
  {
    destFile2 << replaceString(line, s1, s2) << std::endl;
  }
  srcFile.close();
  destFile2.close();
  
  return (0);
}
