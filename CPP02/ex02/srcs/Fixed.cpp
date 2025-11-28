/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:28:17 by camerico          #+#    #+#             */
/*   Updated: 2025/11/28 20:49:04 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

//constructeur de recopie
Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	
	*this = other;
}

//operateur d'affectation
Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_value = other._value;
	}
	return (*this);
}

//Destructeur
Fixed::~Fixed() 
{
	// std::cout << "Destructor called" << std::endl;	
}

//retourne la valeur du nombre à virgule fixe sans la convertir
int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	
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
	// std::cout << "Int constructor called" << std::endl;
	
	this->_value = nb << _bitsFractionnal;			//ca veut dire qu'on va decaller le nb de "_bitsFractionnal" fois vers la gauche
}

//convertit nb en virgule fixe, initialise a 8
// prend 42.42f en parametre et le stock en 42.42 
// Arrondit un float à l'entier le plus proche
Fixed::Fixed(const float f)
{
	// std::cout << "Float constructor called" << std::endl;

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


/***********************
*	Nouveau pour ex02  *
***********************/

//Operateur de comparaison

bool Fixed::operator>(const Fixed& other) const
{
	return this->_value > other._value;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->_value != other._value;
}


//operateurs arithmetiques

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result._value = this->_value + other._value;
	//ou result.getRawBits(this->_value + other._value);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result._value = this->_value - other._value;
	return result;
}

//attention, on doit diviser par 256 ( voir ex 1)
Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result._value = ((this->_value * other._value) / (1 << _bitsFractionnal));
	return result;
}

//attention, on doit multiplier par 256 car sinon ca s'annule (voir ex 2)
Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result._value = (this->_value * (1 << _bitsFractionnal) / other._value);
	return result;	
}



//operateurs d'incrementation/decrementation


//++a ( pre-incrementation) (voir ex03)
Fixed& Fixed::operator++(void)
{
	this->_value++;			//on ajoute 1 a la valeur reelle (valeur brute /256)
	return *this;			//on retourne l'obj modif
}

//a++ (post-incrementation), retourne une copie ( voir ex04)
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);			//on copie l'ancienne valeur
	this->_value++;				//on incremente
	return tmp;					//oon retoune tmp ( l'ancienne valeur)
}

//--a
Fixed& Fixed::operator--(void)
{
	this->_value--;
	return *this;
}

//a--
Fixed Fixed::operator--(int)
{
	Fixed tmp;
	this->_value--;
	return tmp;
}


//fonctions statiques min/max
//il faut faire 2 versions pour chaque , une pour un nb const et un autre pour un nb non const


//min verison non-const
Fixed& Fixed::min(Fixed &a, Fixed& b)
{
	return (a < b) ? a : b;
}

//min version const
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}


const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}





/*ex 1:
Fixed a(2.0f);   // _value = 512
Fixed b(3.0f);   // _value = 768

Fixed c = a * b;
// c._value = (512 × 768) / 256 = 393216 / 256 = 1536
// c.toFloat() = 1536 / 256 = 6.0 




ex 2:
Fixed a(6.0f);   // _value = 1536
Fixed b(2.0f);   // _value = 512

Fixed c = a / b;
// c._value = (1536 × 256) / 512 = 393216 / 512 = 768
// c.toFloat() = 768 / 256 = 3.0 



ex 03 :
Fixed a(5.0f);  // _value = 1280

Fixed b = ++a;

// Dans operator++() :
// 1. this->_value++;         → _value = 1281
// 2. return *this;           → retourne a (référence)
// 
// Résultat : b = a = 1281




ex04 :
Fixed a(5.0f);  // _value = 1280

Fixed c = a++;

// Dans operator++(int) :
// 1. Fixed temp(*this);      → temp._value = 1280 (copie)
// 2. this->_value++;         → _value = 1281
// 3. return temp;            → retourne temp (copie)
//
// Résultat : c = 1280, a = 1281



*/


