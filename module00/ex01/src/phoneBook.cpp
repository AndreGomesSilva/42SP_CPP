/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:01:43 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/03 21:53:15 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

int Phonebook::_numberOfContacts = 0;

Phonebook::Phonebook(void)
{
	std::cout << "Phonebook created" << std::endl;
	this->_numberOfContacts = 0;
	return ;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Phonebook destroyed" << std::endl;
	return ;
}

std::string Phonebook::getInput(std::string message) const
{
	std::string input;
	do
	{
		std::cout << message;
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Field cannot be empty" << std::endl;
	} while (input.empty());
	return (input);
}

void Phonebook::addContact(void)
{
	if (this->_numberOfContacts == 8)
  {
    this->_numberOfContacts = 0;
		std::cout << "Becareful, phonebook is full of contacts if you add a new one it will be overwritten " << std::endl;
  }
	std::string input;
	input = getInput("First name: ");
	this->_contacts[this->_numberOfContacts].setFirstName(input);
	input = getInput("Last name: ");
	this->_contacts[this->_numberOfContacts].setLastName(input);
	input = getInput("Nickname: ");
	this->_contacts[this->_numberOfContacts].setNickName(input);
	input = getInput("Darkest secret: ");
	this->_contacts[this->_numberOfContacts].setDarkSecret(input);
	input = getInput("Phone number: ");
	this->_contacts[this->_numberOfContacts].setPhoneNumber(input);
	if (this->_numberOfContacts < 8)
		this->_numberOfContacts++;
	std::cout << "Contact added successfully" << std::endl;
}

void	Phonebook::displayTableHeader(void) const
{
	std::cout << std::right << std::setw(10) << "Index"
				<< " | ";
	std::cout << std::right << std::setw(10) << "First Name"
				<< " | ";
	std::cout << std::right << std::setw(10) << "Last Name"
				<< " | ";
	std::cout << std::right << std::setw(10) << "Nick Name"
				<< " | " << std::endl;
}

void	Phonebook::displayAllTableHeader(void) const
{
	std::cout << std::right << std::setw(10) << "Index"
				<< " | ";
	std::cout << std::right << std::setw(10) << "First Name"
				<< " | ";
	std::cout << std::right << std::setw(10) << "Last Name"
				<< " | ";
	std::cout << std::right << std::setw(10) << "Nick Name"
				<< " | " ;
	std::cout << std::right << std::setw(10) << "Phone"
				<< " | ";
	std::cout << std::right << std::setw(10) << "Secret"
	           << " | " << std::endl;
}

std::string Phonebook::displayTableContent(const std::string &content) const
{
  std::string newContent;
  if (content.length() > 10) {
    newContent = content.substr(0, 10);
    newContent.push_back('.');
  } else
    newContent = content;
  return (newContent);
}


void	Phonebook::displayContact(Contact contact, int index) const
{
	std::cout << std::right << std::setw(10) << index + 1 << " | ";
	std::cout << std::right << std::setw(10) << displayTableContent(contact.getFirstName()) << " | ";
	std::cout << std::right << std::setw(10) << displayTableContent(contact.getLastName()) << " | ";
	std::cout << std::right << std::setw(10) << displayTableContent(contact.getNickName()) << " | " << std::endl;
}

void Phonebook::displayAllContentOfContact(const Contact& contact, int index) const
{
  std::cout << "Index: " << index + 1 << std::endl;
  std::cout << "First Name: " << contact.getFirstName() << std::endl;
  std::cout << "Last Name: " << contact.getLastName() << std::endl;
  std::cout << "Nick Name: " << contact.getLastName() << std::endl;
  std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
  std::cout << "Secret: " << contact.getDarkSecret() << std::endl;
}

void Phonebook::chooseContact(const Contact *contacts) const
{
    std::string  input;
    
    input  = getInput("Type the ID of the contact that do you want to see or Q to leave: ");
    if (input.length() == 1 && (input[0] == 'Q' || input[0]  == 'q'))
        return ;
    if (input.length() ==  1  && input[0] >= '1' && input[0] <= '8')
    {
        int index;
        index = atoi(input.c_str())  -  1;
        if (contacts[index].getFirstName().empty())
            std::cout << "This Contact does not exist" << std::endl;
        else {
            displayAllContentOfContact(contacts[index], index);
        }
    }
    else {
        std::cout << "Please type a valid ID" << std::endl;
    }
}

void Phonebook::searchContact(void) const
{
	if (this->_numberOfContacts == 0)
	{
		std::cout << "Phonebook is empty" << std::endl;
		return ;
	}
	for (int i = 0; i < 8; i++)
	{
		if (i == 0)
			displayTableHeader();
    if (this->_contacts[i].getFirstName().empty())
      break;
		displayContact(this->_contacts[i], i);
	}
	chooseContact(this->_contacts);
}
