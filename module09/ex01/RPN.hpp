#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cctype>
#include <sstream>
#include <stdexcept>
#include <string>
#include <list>

class RPN{
    private:
        std::string &_input;
        std::stack<int,  std::list<int> > _stack;

    public:
        RPN(std::string &input);
        RPN(RPN &copy);
        ~RPN();

        RPN &operator=(RPN &copy);
        bool validateInput();
        bool isOperator(char c);
        int calculator();
};

#endif
