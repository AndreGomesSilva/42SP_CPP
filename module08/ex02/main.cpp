#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

void testWithDeque() {
  // Test 1: Default Constructor and Basic Operations
  std::cout << "Test 1: Basic stack operations\n";
  MutantStack<int, std::deque<int> > mstack;
  std::cout << "Stack created. Is empty: " << (mstack.empty() ? "Yes" : "No")
            << "\n";

  mstack.push(10);
  mstack.push(20);
  mstack.push(30);
  std::cout << "Pushed 10, 20, 30. Current top: " << mstack.top()
            << ", Size: " << mstack.size() << "\n";

  mstack.pop();
  std::cout << "Popped top. Current top: " << mstack.top()
            << ", Size: " << mstack.size() << "\n";

  // Test 2: Copy Constructor
  std::cout << "\nTest 2: Copy constructor\n";
  MutantStack<int> copyStack(mstack);
  std::cout << "Copied stack. Current top: " << copyStack.top()
            << ", Size: " << copyStack.size() << "\n";

  copyStack.push(40);
  std::cout << "Pushed 40 to copied stack. Current top: " << copyStack.top()
            << ", Size: " << copyStack.size() << "\n";
  std::cout << "Original stack size: " << mstack.size() << "\n";

  // Test 3: Assignment Operator
  std::cout << "\nTest 3: Assignment operator\n";
  MutantStack<int> assignedStack;
  assignedStack = copyStack;
  std::cout << "Assigned stack. Current top: " << assignedStack.top()
            << ", Size: " << assignedStack.size() << "\n";

  assignedStack.pop();
  std::cout << "Popped top of assigned stack. Current top: "
            << assignedStack.top() << ", Size: " << assignedStack.size()
            << "\n";
  std::cout << "Copied stack size after pop in assigned stack: "
            << copyStack.size() << "\n";

  // Test 4: Iterator
  std::cout << "\nTest 4: Iterator\n";
  mstack.push(50);
  mstack.push(60);
  std::cout << "Elements in the stack: ";
  for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  // Test 5: Const Iterator
  std::cout << "\nTest 5: Const iterator\n";
  const MutantStack<int> constStack(mstack);
  std::cout << "Elements in the const stack: ";
  for (MutantStack<int>::const_iterator cit = constStack.begin();
       cit != constStack.end(); ++cit) {
    std::cout << *cit << " ";
  }
  std::cout << "\n";

  // Test 6: Reverse Iterator
  std::cout << "\nTest 6: Reverse iterator\n";
  std::cout << "Elements in the stack in reverse order: ";
  for (MutantStack<int>::reverse_iterator rit = mstack.rbegin();
       rit != mstack.rend(); ++rit) {
    std::cout << *rit << " ";
  }
  std::cout << "\n";

  // Test 7: Const Reverse Iterator
  std::cout << "\nTest 7: Const reverse iterator\n";
  std::cout << "Elements in the const stack in reverse order: ";
  for (MutantStack<int>::const_reverse_iterator crit = constStack.rbegin();
       crit != constStack.rend(); ++crit) {
    std::cout << *crit << " ";
  }
  std::cout << "\n";

  std::cout << "\nAll tests completed.\n";
}

void testWithVector(){
  std::cout << "Test with vector" << std::endl;
  MutantStack<int, std::vector<int> > mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);
  MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
  MutantStack<int, std::vector<int> >::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int, std::vector<int> > s(mstack);
}

void testWithList(){
  std::cout << "Test with list" << std::endl;
  MutantStack<int, std::list<int> > mstack;
  mstack.push(5);
  mstack.push(17);
   std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);
  MutantStack<int, std::list<int> >::iterator it = mstack.begin();
  MutantStack<int, std::list<int> >::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int, std::list<int> > s(mstack);
}

void testSubject() {
  std::cout << "------Subject tests------" << std::endl;
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
 }

int main(void) {
  testSubject();
  std::cout << "------------" << std::endl;
  std::cout << std::endl;
  testWithDeque();
  std::cout << "------------" << std::endl;
  std::cout << std::endl;
  testWithVector();
  std::cout << "------------" << std::endl;
  std::cout << std::endl;
  testWithList();
  std::cout << "------------" << std::endl;
  std::cout << std::endl;
  return 0;
}
