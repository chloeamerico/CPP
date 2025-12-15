/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:59:40 by camerico          #+#    #+#             */
/*   Updated: 2025/12/15 20:45:16 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

//Forme Canonique

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& copy) : AMateria(copy) {}

Ice& Ice::operator=(const Ice& copy)
{
	if (this != &copy)
		AMateria::operator=(copy);
	return *this;
}

Ice::~Ice();

//fonctions membres heritees de la classe AMateria


AMateria* Ice::clone() const
{
	return new Ice(*this);		//c'est un Ice cast en AMateria car c'est le type de retour de la fonction
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
}