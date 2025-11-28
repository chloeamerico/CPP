/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:28:17 by camerico          #+#    #+#             */
/*   Updated: 2025/11/27 17:10:15 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

//constructeur de recopie
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	
	*this = other;
}

//operateur d'affectation
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_value = other._value;
	}
	return (*this);
}

//Destructeur
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



/************************
*   nouveau de l'ex01	*
************************/


//convertit nb en virgule fixe, initialise a 8
// prend 5 et le stock en 5.0
Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	
	this->_value = nb << _bitsFractionnal;			//ca veut dire qu'on va decaller le nb de "_bitsFractionnal" fois vers la gauche
}

//convertit nb en virgule fixe, initialise a 8
// prend 42.42f en parametre et le stock en 42.42 
// Arrondit un float à l'entier le plus proche
Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;

	this->_value = roundf(f * (1 << _bitsFractionnal));
}


//convertit la valeur en virgule fixe en nombre à virgule flottante
float Fixed::toFloat( void ) const
{
	return (float)_value / (1 << _bitsFractionnal);
}


//convertit la valeur en virgule fixe en nombre entier.
int Fixed::toInt( void ) const
{
	return _value >> _bitsFractionnal;
}

//permet d'afficher un objet Fixed avec std::cout 
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}