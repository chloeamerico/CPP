/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:04:15 by camerico          #+#    #+#             */
/*   Updated: 2025/10/27 18:15:22 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


/****************************************************************
*																*
*						Constructeurs 							*
*				initialise les attributs a vide					*
*																*
****************************************************************/

Contact::Contact(void)
{
	this->_first_name = "";
	this->_last_name = "";
	this->_nickname = "";
	this->_phone_number = "";
	this->_darkest_secret = "";
}


/****************************************************************
*																*
*						Les Setter 								*
*	Fonction utilise pour modifier l'attribut, ne renvoie rien​	 *
*																*
****************************************************************/

void	Contact::setFirstName(std::string first_name)
{
	this->_first_name = first_name;
}

void Contact::setLastName(std::string last_name)
{
	this->_last_name = last_name;
}

void	Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phone_number)
{
	this->_phone_number = phone_number;
}

void	Contact::setDarkestSecret(std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}


/****************************************************************
*																*
*						Les Getter 								*
*	fonction publique qui permet de lire (et retourner) la 		*
*			valeur d'un attribut privé sans rien modifier​		 *
*																*
****************************************************************/

std::string Contact::getFirstName(void) const
{
	return this->_first_name;
}

std::string	Contact::getLastName(void) const
{
	return this->_last_name;
}

std::string	Contact::getNickname(void) const
{
	return this->_nickname;
}

std::string Contact::getPhoneNumber(void) const
{
	return this->_phone_number;
}

std::string	Contact::getDarkestSecret(void) const
{
	return this->_darkest_secret;
}

