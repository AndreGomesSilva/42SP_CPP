/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:25:08 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/24 21:47:11 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
  public:
	Contact(void);
	~Contact(void);

	void add(void);

  private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _darkSecret;
	std::string _phoneNumber;
};

#endif
