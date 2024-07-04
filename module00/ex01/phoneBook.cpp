/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:01:43 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/03 21:53:15 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"
#include <iomanip>
#include <ios>
#include <iostream>

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

static std::string getInput(std::string message)
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

static void	displayTableHeader(void)
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

static void	displayContact(Contact contact, int index)
{
	std::cout << std::right << std::setw(10) << index + 1 << " | ";
	std::cout << std::right << std::setw(10) << contact.getFirstName() << " | ";
	std::cout << std::right << std::setw(10) << contact.getLastName() << " | ";
	std::cout << std::right << std::setw(10) << contact.getNickName() << " | " << std::endl;
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
}