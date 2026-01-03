/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:25:44 by camerico          #+#    #+#             */
/*   Updated: 2026/01/03 18:58:32 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

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

		//
};

#include "Array.tpp"

#endif