/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:00:59 by camerico          #+#    #+#             */
/*   Updated: 2026/01/02 16:43:30 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>  // Pour rand()
#include <ctime>    // Pour time()
#include <iostream>
#include <typeinfo>	//pour l'exception std::bad_cast

class Base {
	
	public :
		virtual ~Base();
};

Base * generate(void);		//instancie aleatoirement A, B ou C
void identify(Base* p);		// affiche le type via pointeur
void identify(Base& p);		//affiche le type par reference


#endif