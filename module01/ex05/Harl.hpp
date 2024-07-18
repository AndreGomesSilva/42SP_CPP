#ifndef __HARL_H__
# define __HARL_H__

#include <iostream>
#include <string>

class Harl
{
private:
  void debug( void );
  void info( void );
  void warning( void );
  void error( void );
public:
  void complain( std::string level );
};

# endif
