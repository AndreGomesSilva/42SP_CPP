#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class Phonebook
{
  public:
	Contact contact[8];

	Phonebook(void);
	~Phonebook(void);

	void add(void);
	// Contact seach(int contact);

  private:
	int _numberOfContacts;
};

#endif
