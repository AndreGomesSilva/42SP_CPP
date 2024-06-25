/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:26:28 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/24 21:34:48 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"
#include <iostream>

int main(void) {

  Phonebook phoneBook;

  while (1)
  {
    std::string command;
    std::cout << "Enter with a command ADD, SEARCH or EXIT: ";
    std::getline(std::cin, command);
    if (command == "EXIT")
      break;
    if (command == "ADD")
      phoneBook.add();
    // if (command == "SEARCH")
    //   phoneBook.search();
  }
  return (0);
}
