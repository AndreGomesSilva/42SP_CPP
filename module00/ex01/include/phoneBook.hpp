#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class Phonebook {
public:
  Phonebook(void);
  ~Phonebook(void);

  void addContact(void);
  void searchContact(void) const;

private:
  static int _numberOfContacts;
  Contact _contacts[8];
};

#endif
