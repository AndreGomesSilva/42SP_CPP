/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:34:50 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/20 20:34:51 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  else {
    std::string separator = "";
    for (int i = 1; i < argc; i++) {
      std::string arg = argv[i];

      for (int k = 0; arg[k] != '\0'; ++k) {
        arg[k] = std::toupper(static_cast<unsigned char>(arg[k]));
      }
      std::cout << separator << arg;
      separator = " ";
    }
  }
  std::cout << std::endl;
  return 0;
}
