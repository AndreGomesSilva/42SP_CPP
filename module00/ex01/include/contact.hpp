/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:25:08 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/20 19:33:16 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
  public:
	Contact(void);
	~Contact(void);

	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setNickName(std::string nickname);
	void setDarkSecret(std::string darkSecret);
	void setPhoneNumber(std::string phoneNumber);
	std::string getLastName(void) const;
	std::string getNickName(void) const;
	std::string getDarkSecret(void) const;
	std::string getPhoneNumber(void) const;
	std::string getFirstName(void) const;

  private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _darkSecret;
	std::string _phoneNumber;
};

#endif
