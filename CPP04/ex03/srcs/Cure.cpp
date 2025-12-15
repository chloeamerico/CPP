/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:01:17 by camerico          #+#    #+#             */
/*   Updated: 2025/12/15 21:02:31 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cure.hpp"
#include "ICharacter.hpp"

//Forme Canonique

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& copy) : AMateria(copy) {}

Cure& Cure::operator=(const Cure& copy)
{
	if (this != &copy)
		AMateria::operator=(copy);
	return *this;
}

Cure::~Cure() {}

//fonctions membres heritees de la classe AMateria


AMateria* Cure::clone() const
{
	return new Cure(*this);		//c'est un Cure cast en AMateria car c'est le type de retour de la fonction
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}