/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:34:36 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/20 20:34:37 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <cstdlib>

class Phonebook {
public:
  Phonebook(void);
  ~Phonebook(void);

  void addContact(void);
  void searchContact(void) const;

private:
  static int _numberOfContacts;
  Contact _contacts[8];

  void displayContact(Contact contact, int index) const;
  void displayAllContentOfContact(const Contact& contact, int index) const;
  void displayTableHeader(void) const;
  void displayAllTableHeader(void) const;
  void chooseContact(const Contact *contacts) const;
  std::string getInput(std::string prompt) const;
  std::string displayTableContent(const std::string &content) const;
};

#endif
