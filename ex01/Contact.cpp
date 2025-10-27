/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:04:15 by camerico          #+#    #+#             */
/*   Updated: 2025/10/27 17:49:59 by camerico         ###   ########.fr       */
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
*	Fonction utilise pour modifier l'attribut, ne renvoie rien​	 *
*																*
****************************************************************/