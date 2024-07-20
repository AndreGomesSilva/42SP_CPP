/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:25:01 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/20 20:00:49 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(void) { return; }

Contact::~Contact(void) { return; }

void Contact::setFirstName(std::string firstName) {
    this->_firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
    this->_lastName = lastName;
}

void Contact::setNickName(std::string nickname) {
    this->_nickName = nickname;
}

void Contact::setDarkSecret(std::string darkSecret) {
    this->_darkSecret = darkSecret;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
     this->_phoneNumber = phoneNumber;
}

std::string Contact::getFirstName(void) const { return (this->_firstName); }

std::string Contact::getLastName(void) const { return (this->_lastName); }

std::string Contact::getNickName(void) const { return (this->_nickName); }

std::string Contact::getDarkSecret(void) const { return (this->_darkSecret); }

std::string Contact::getPhoneNumber(void) const { return (this->_phoneNumber); }
