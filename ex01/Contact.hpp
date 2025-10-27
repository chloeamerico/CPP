/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:03:51 by camerico          #+#    #+#             */
/*   Updated: 2025/10/27 17:38:32 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Déclaration de la classe Contact
//une page du carnet

/*	classe stocke les informations personnelles d'un contact, telles que
*	le prénom, le nom, le surnom, le numéro de téléphone et le secret le plus 
*	sombre.*/

#ifndef CONTACT_HPP
#define CONTACT_HPP


#include <string>

class Contact
{
	private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;

	public:
	Contact();		//constructeur

	//Setter
	void	setFirstName(std::string first_name);
	void	setLastName(std::string last_name);
	void	setNickname(std::string nickname);
	void	setPhoneNumber(std::string phone_number);
	void	setDarkestSecret(std::string darkest_secret);

	//fonctions pour lire les attributs privés, mais sans les modifs
	// avec le const, on ne modiifie rien

	std::string getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickname(void) const;
	std::string	getPhoneNumber(void) const;
	std::string	getDarkestSecret(void) const;
};


#endif