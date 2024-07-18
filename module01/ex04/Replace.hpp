#ifndef __REPLACE_H__
# define __REPLACE_H__

#include <iostream>
#include <fstream>
# include <string>

typedef enum e_error {
  OK = 0,
  ERROR = - 1,
} t_error;

//functions
std::string replaceString(std::string const &source, std::string const &oldStr, std::string const &newStr);
std::string replaceExtension(std::string const &str, std::string const &ext);

#endif
