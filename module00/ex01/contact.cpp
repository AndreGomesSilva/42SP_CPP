/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:25:01 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/24 21:46:54 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <iostream>

Contact::Contact(void)
{
  std::cout << "Contact created" << std::endl;
  return ;
}

Contact::~Contact(void)
{
  std::cout << "Contact destroyed" << std::endl;
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

void Contact::add(void)
{
	this->_firstName = getInput("First name: ");
	this->_lastName = getInput("Last name: ");
	this->_nickName = getInput("Nickname: ");
	this->_darkSecret = getInput("Darkest secret: ");
  this->_phoneNumber = getInput("Phone number: ");

	std::cout << "Contact added successfully" << std::endl;

  return ;
}

// void Contact::search(void)
// {
//   if (this->_numberOfContacts == 0)
//   {
//     std::cout << "No contacts found" << std::endl;
//     return;
//   }
//   std::cout << "Index|First Name|Last Name|Nickname" << std::endl;
//   for (int i = 0; i < this->_numberOfContacts; i++)
//   {
//     std::cout << i << "|";
//     std::cout << this->_firstName << "|";
//     std::cout << this->_lastName << "|";
//     std::cout << this->_nickName << "|" << std::endl;
// }
