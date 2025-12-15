/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:06:24 by camerico          #+#    #+#             */
/*   Updated: 2025/12/15 19:53:37 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//Forme Canonique

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria& copy) : _type(copy._type) {}

AMateria& AMateria::operator=(const AMateria& copy) {
	
	if (this != &copy)
		this->_type = copy._type;
	
	return *this;
	
}

AMateria::~AMateria() {}


//Fonctions membres

//Returns the materia type / une reference plutot qu'une copie
std::string const & AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
