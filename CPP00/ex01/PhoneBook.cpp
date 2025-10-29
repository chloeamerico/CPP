/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:04:54 by camerico          #+#    #+#             */
/*   Updated: 2025/10/28 18:10:58 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Implémentation de la classe PhoneBook
// ne peut contenir que 8 contacts max, si on y ajoute un 9eme, il remplace le plsu ancien
//doit gerer : ADD, SEARCH et EXIT

#include "PhoneBook.hpp"


PhoneBook::PhoneBook() : _nb_contacts(0), _current_contact(0) {}

PhoneBook::~PhoneBook() {}

//pour ajouter un contact
void	PhoneBook::addContact()
{
	std::string input;
	
	while(input.empty())
	{
		std::cout << "First Name : ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Le champs ne peut pas etre vide" << std::endl;
	}
	_contacts[_current_contact].setFirstName(input);
	input.clear();

	while(input.empty())
	{
		std::cout << "Last Name : ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Le champs ne peut pas etre vide" << std::endl;
	}
	_contacts[_current_contact].setLastName(input);
	input.clear();

	while(input.empty())
	{
		std::cout << "Nickname : ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Le champs ne peut pas etre vide" << std::endl;
	}
	_contacts[_current_contact].setNickname(input);
	input.clear();

	while(input.empty())
	{
		std::cout << "Phone Number : ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Le champs ne peut pas etre vide" << std::endl;
	}
	_contacts[_current_contact].setPhoneNumber(input);
	input.clear();

	while(input.empty())
	{
		std::cout << "Darkest Secret : ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Le champs ne peut pas etre vide" << std::endl;
	}
	_contacts[_current_contact].setDarkestSecret(input);
	input.clear();

	if (_nb_contacts < 8)
		_nb_contacts++;
	_current_contact = (_current_contact + 1) % 8;
}


//tronque a 10 char max, si plus de 10 on en affiche 9 avec un .

static std::string	truncate(const std::string &s)
{
	if(s.size() > 10)
		return s.substr(0, 9) + ".";
	return s;
}



void PhoneBook::searchContact()
{
	if (_nb_contacts == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return;
	}
	
	std::cout << std::right << std::setw(10) << "Index" << "|"
				<< std::right << std::setw(10) << "First Name" << "|"
				<< std::right << std::setw(10) << "Last Name" << "|"
				<< std::right << std::setw(10) << "Nickname" << std::endl;
	
	for (int i = 0; i < _nb_contacts; ++i)
	{
		std::cout 	<< std::right << std::setw(10) << i << "|"
					<< std::right << std::setw(10) << truncate(_contacts[i].getFirstName()) << "|"
					<< std::right << std::setw(10) << truncate(_contacts[i].getLastName()) << "|"
					<< std::right << std::setw(10) << truncate(_contacts[i].getNickname()) << "|"
					<< std::endl;
	}

	std::cout << "Enter an index to see the contact: ";
	
	std::string	line;
	
	if (!std::getline(std::cin, line))
	{
		std::cout << "Bye ! Return to the menu" << std::endl;
		return;
	}
	
	//on valide le format de l'index qui a ete rentre

	//est ce que c'est bien un entier (avec stringstream)
	std::stringstream ss(line);
	int index = -1;
	if(!(ss >> index) || !(ss.eof()))
	{
		std::cout << "Invalid format, you're back to the menu" << std::endl;
		return;
	}
	
	//verif que l'index est bien entre 0 et le nb de contact
	if(index < 0 || index >= _nb_contacts)
	{
		std::cout << "Index is out of range" << std::endl;
		return;
	}
	
	//si l'index est correct, on affiche la fiche du contact
	
	std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
}