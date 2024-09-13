#include "RPN.hpp"

RPN::RPN(std::string &input) : _input(input) {
  _stack = std::stack<int, std::list<int> >();
};

RPN::RPN(RPN &toCopy) : _input(toCopy._input), _stack(toCopy._stack) {
}

RPN::~RPN() {}

RPN &RPN::operator=(RPN &toCopy) {
  if (this != &toCopy) {
    _input = toCopy._input;
    _stack = toCopy._stack;
  }
  return *this;
}

bool RPN::isOperator(char c) {
  if (c == '*' || c == '/' || c == '-' || c == '+')
    return true;
  return false;
}

static void removeSpaces(std::string &str) {
  std::string::iterator newStr = str.begin();
  for (std::string::iterator readPos = str.begin(); readPos != str.end();
       ++readPos) {
    if (*readPos != ' ') {
      *newStr = *readPos;
      ++newStr;
    }
  }
  str.erase(newStr, str.end());
}

bool RPN::validateInput() {
  int numbers = 0;
  int operators = 0;
  std::string::iterator next;
  for (std::string::iterator it = _input.begin(); it != _input.end(); ++it) {
    next = it + 1;
    if (std::isspace(*it)) {
      if (next != _input.end() && (!std::isdigit(*next) && !isOperator(*next)))
        return false;
    } else if (std::isdigit(*it)) {
      if (next != _input.end() && !std::isspace(*next))
        return false;
      numbers++;
    } else if (isOperator(*it)) {
      if (next != _input.end() && !std::isspace(*next))
        return false;
      operators++;
    } else
      return false;
  }
  if (!operators || !numbers)
    return false;
  if ((numbers - 1) != operators)
    return false;
  return true;
}

static int charToInt(char c) {
  std::stringstream ss;
  ss << c;
  int number;
  ss >> number;
  return number;
}

int RPN::calculator() {
  int firstNumber;
  int secondNumber;
  int result;

  removeSpaces(_input);
  for (std::string::iterator it = _input.begin(); it != _input.end(); ++it) {
    if (isdigit(*it)) {
      _stack.push(charToInt(*it));
    } else {
      if (_stack.size() < 2) {
        throw std::invalid_argument("Error: Insufficient operands for operation");
      }
      firstNumber = _stack.top();
      _stack.pop();
      secondNumber = _stack.top();
      _stack.pop();

      switch (*it) {
      case '+':
        result = secondNumber + firstNumber;
        break;
      case '-':
        result = secondNumber - firstNumber;
        break;
      case '*':
        result = secondNumber * firstNumber;
        break;
      case '/':
        if (firstNumber == 0) {
          throw std::invalid_argument("Error: Division by zero");
        }
        result = secondNumber / firstNumber;
        break;
      default:
        throw std::invalid_argument("Error: Problem with operators");
      }
      _stack.push(result);
    }
  }
  if (_stack.size() != 1) {
    throw std::invalid_argument("Error: Invalid RPN expression");
  }
  return _stack.top();
}
