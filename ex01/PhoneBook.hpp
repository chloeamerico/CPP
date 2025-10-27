/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:04:30 by camerico          #+#    #+#             */
/*   Updated: 2025/10/27 19:23:48 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP


#include "Contact.hpp"


class PhoneBook
{
	private:
	Contact _contacts[8];
	int		_nb_contacts;			//cb de contacts actuellement (de 0 a 8)
	int		_current_contact;		//position actuelle ou ajouter le prochain contact (de 0 a 7)
	
	public:
	PhoneBook();
	~PhoneBook();
	

	//pour ADD :
	void addContact();

	//pour SEARCH (affiche les contacts et demande l'index)
	void searchContact();
};

#endif