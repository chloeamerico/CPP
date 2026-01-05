/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:25:44 by camerico          #+#    #+#             */
/*   Updated: 2026/01/05 14:28:03 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <iostream>
#include <exception>

template <typename T>
class Array
{
	private :
		T*	_arr;		//pointeur vers le tab alloue dynamiquement
		unsigned int _sizeTab;		//nb d'elements dans le tableau

	public :

		//form canonique
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		Array& operator=(const Array& copy);
		~Array();

		//operator []	--> permet d'acceder directement a array[index]
		//doit retourner une reference a l'element a la position index
		//si index hors limite, throw une exception
		
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;	//version pour lire un tab const

		class IndexTooHighException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};

		unsigned int size(void) const;
};

#include "./../srcs/Array.tpp"

#endif