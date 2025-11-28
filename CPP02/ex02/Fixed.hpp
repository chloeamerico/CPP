/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:46:45 by camerico          #+#    #+#             */
/*   Updated: 2025/11/28 19:33:02 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed {

	private :

	int _value;
	static const int _bitsFractionnal = 8;

	
	public :

	//form canonique :
	Fixed();								//Constructeur par defaut
	Fixed(const Fixed& other);				//Constructeur de copie
	Fixed& operator=(const Fixed& other) ;	//Operateur d'affectation
	~Fixed();								//Destructeur

	int getRawBits( void ) const;			//retourne la valeur du nombre à virgule fixe sans la convertir
	void setRawBits( int const raw );		//initialise la valeur du nombre à virgule fixe avec celle passée en paramètre.
	


	Fixed(const int nb);		//convertit nb en virgule fixe, initialise a 8		// prend 5 et le stock en 5.0
	Fixed(const float f);		//convertit nb en virgule fixe, initialise a 8		// prend 42.42f en parametre et le stock en 42.42 

	float toFloat( void ) const;		//convertit la valeur en virgule fixe en nombre à virgule flottante
	int toInt( void ) const;			//convertit la valeur en virgule fixe en nombre entier.
	


	/***********************
	*	Nouveau pour ex02  *
	***********************/

	// les operateurs de comparaison

	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	//les operateurs arithmetiques

	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	// operateur d'incrementation/decrementation

	Fixed& operator++(void);		//++a
	Fixed operator++(int);			//a++
	Fixed& operator--(void);		//--a
	Fixed operator--(int);			//a--
	
	//fonctions statiques min/max

	static Fixed& min(Fixed &a, Fixed& b);					//pour pouvoir modif un object non const
	static const Fixed& min(const Fixed& a, const Fixed& b);	//pour pouvoir ;odif un object const
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
	
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif