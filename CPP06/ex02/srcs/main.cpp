/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:34:13 by camerico          #+#    #+#             */
/*   Updated: 2026/01/02 16:39:06 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	srand(time(NULL));		//on initialise 1 fois

	Base* obj = generate();		// on genere un obj aleatoirement

	std::cout << "---- test pointeur : ----" << std ::endl;
	identify(obj);
	std::cout << std::endl;

	std::cout << "---- test reference : ----" << std ::endl;
	identify(*obj);
	
	delete obj;

	return 0;

}