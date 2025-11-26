/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:23:36 by camerico          #+#    #+#             */
/*   Updated: 2025/11/26 17:16:19 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


//Constructeur par defaut qui initialise a 0
Fixed::Fixed() : _value(0) 
{
	std::cout << "Default constructor called" << std::endl;
}


//Constructeur de recopie (cree une copie d'un objet existant vers un autre qu'on cree)
//other est une référence vers l'objet qu'on veut copier
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}


//operateur d'affectation (copie un obj qui existe vers un autre qui existe deja)
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &other)			//protection d'auto affectation, pr eviter de faire Fixed a(a)
	{
		this->_value = other.getRawBits();
	}
	
	return(*this); 				//on retourne l'objet lui-meme
}


//destructeur
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


//retourne la valeur du nombre à virgule fixe sans la convertir
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	
	return(this->_value);
}


//initialise la valeur du nombre à virgule fixe avec celle passée en paramètre.
void Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}
