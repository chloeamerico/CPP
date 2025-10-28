/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:03:33 by camerico          #+#    #+#             */
/*   Updated: 2025/10/28 17:47:21 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phonebook;
	std::string cmd;		//stocke la cmd tapee par l'utilisateur

	std::cout << "Welcome to the PhoneBook!" << std::endl;
	std::cout << "You can ADD , SEARCH or EXIT " << std::endl;

	while (true)
	{
		if (!std::getline(std::cin, cmd))
		{
			std::cout << "Bye!" << std::endl;
			return;
		}
		if (cmd == "ADD")
			phonebook.addContact();
		else if (cmd == "SEARCH")
			phonebook.searchContact();
		else if (cmd == "EXIT")
		{
			std::cout << "Bye" << std::endl;
			break;
		}
		else if (cmd.empty()) 		//pour une ligne vide
			continue;
		else
			std::cout << "Unknown command : You can ADD, SEARCH or EXIT" << std::endl;
	}
}