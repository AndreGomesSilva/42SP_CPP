/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:01:43 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/24 21:38:57 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"
#include <iostream>

Phonebook::Phonebook( void ){

  std::cout << "Phonebook created" << std::endl;

  this->_numberOfContacts = 0;

  return ;
}

Phonebook::~Phonebook( void ){

  std::cout << "Phonebook destroyed" << std::endl;

  return ;
}

void Phonebook::add(void)
{
	Contact	contact;

	if (this->_numberOfContacts == 8)
	{
		std::cout << "Phonebook is full" << std::endl;
		return;
	}
	else
	{
    contact.add();
		this->contact[this->_numberOfContacts++] = contact;
	}
}
