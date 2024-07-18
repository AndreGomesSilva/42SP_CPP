#include "Replace.hpp"

std::string replaceString(std::string const &source, std::string const &oldStr, std::string const &newStr)
{
  std::string result;
  size_t pos = 0;
  size_t len = oldStr.length();
  
  while (true) {

    size_t foundPos = source.find(oldStr, pos);

    if (foundPos == std::string::npos)
    {
      result += source.substr(pos);
      break;
    }

    result += source.substr(pos, foundPos - pos);
    result += newStr;
    pos = foundPos + len;
  }
  return (result);
}

std::string replaceExtension(std::string const &str, std::string const &ext)
{
  size_t pos = str.find_last_of(".");
  if (pos == std::string::npos)
    return (str + ext);
  return (str.substr(0, pos) + ext);
}
