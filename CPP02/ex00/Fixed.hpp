/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:03:07 by camerico          #+#    #+#             */
/*   Updated: 2025/11/26 16:23:15 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

	private :

	int _value;
	static const int _bitsFractionnal = 8;

	
	public :

	//form canonique :
	Fixed();								//Constructeur par defaut
	Fixed(const Fixed& other);				//Constryucteur de copie
	Fixed& operator=(const Fixed& other) ;	//Operateur d'affectation
	~Fixed();								//Destructeur

	int getRawBits( void ) const;			//retourne la valeur du nombre à virgule fixe sans la convertir
	void setRawBits( int const raw );		//initialise la valeur du nombre à virgule fixe avec celle passée en paramètre.
	
};

#endif