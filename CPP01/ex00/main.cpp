/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:37:29 by camerico          #+#    #+#             */
/*   Updated: 2025/11/04 19:29:12 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "test avec randomchump :" << std::endl;
	
	randomChump("Lolo");	//cree sur la stack (se detruit automatiquement)
	
	std::cout << "test avec newZombie :" << std::endl;

	Zombie	*test = newZombie("chloe");		//cree sur la heap
	test->announce();						//utilise un pointeur

	delete test;			//destruction manuelle

	return 0;
}