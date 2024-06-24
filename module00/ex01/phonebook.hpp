#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include <string>
class Contact {
 
public: 
  Contact(void);
  ~Contact(void);
  
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _darkSecret;
    unsigned int _phoneNumber;
};

class Phonebook {
    public:
    
    Contact contact[8];
    
    Phonebook(void);
    ~Phonebook(void);
    
    int add(Contact contact);
    // Contact seach(int contact);
    
};

#endif