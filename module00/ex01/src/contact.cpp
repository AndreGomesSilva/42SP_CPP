/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:25:01 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/16 17:43:56 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(void) { return; }

Contact::~Contact(void) { return; }

void Contact::setFirstName(std::string firstName) {
  if (firstName.length() > 10) {
    this->_firstName = firstName.substr(0, 9);
    this->_firstName.push_back('.');
  } else
    this->_firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
  if (lastName.length() > 10) {
    this->_lastName = lastName.substr(0, 9);
    this->_lastName.push_back('.');
  } else
    this->_lastName = lastName;
}

void Contact::setNickName(std::string nickname) {
  if (nickname.length() > 10) {
    this->_nickName = nickname.substr(0, 9);
    this->_nickName.push_back('.');
  } else
    this->_nickName = nickname;
}

void Contact::setDarkSecret(std::string darkSecret) {
  if (darkSecret.length() > 10) {
    this->_darkSecret = darkSecret.substr(0, 9);
    this->_darkSecret.push_back('.');
  } else
    this->_darkSecret = darkSecret;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
  if (phoneNumber.length() > 10) {
    this->_phoneNumber = phoneNumber.substr(0, 9);
    this->_phoneNumber.push_back('.');
  } else
    this->_phoneNumber = phoneNumber;
}

std::string Contact::getFirstName(void) const { return (this->_firstName); }

std::string Contact::getLastName(void) const { return (this->_lastName); }

std::string Contact::getNickName(void) const { return (this->_nickName); }

std::string Contact::getDarkSecret(void) const { return (this->_darkSecret); }

std::string Contact::getPhoneNumber(void) const { return (this->_phoneNumber); }
