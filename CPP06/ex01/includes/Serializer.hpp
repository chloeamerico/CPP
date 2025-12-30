/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:52:53 by camerico          #+#    #+#             */
/*   Updated: 2025/12/30 19:48:07 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP 
#define SERIALIZER_HPP

#include "Data.hpp"
#include <iostream>
#include <stdint.h>		//pour uintptr_t

class Serializer {
	
	private :
		Serializer();
		Serializer(const Serializer& copy);
		Serializer& operator=(const Serializer& copy);
		~Serializer();
		
	public :
		static uintptr_t serialize(Data* ptr);		//prend un pointeur et le converti vers un unsigned int
		static Data* deserialize(uintptr_t raw);	//prend un unsigned int et le converti vers un pointeur data
};


#endif