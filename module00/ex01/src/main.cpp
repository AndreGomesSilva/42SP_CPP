/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:26:28 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/20 20:14:11 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {

  Phonebook phoneBook;

  while (true)
  {
    std::string command;
    std::cout << "Enter with a command ADD, SEARCH or EXIT: ";
    if (std::cin.eof())
      break;
    std::getline(std::cin, command);
    if (command == "EXIT")
      break;
    if (command == "ADD")
      phoneBook.addContact();
    if (command == "SEARCH")
      phoneBook.searchContact();
  }
  return (0);
}
