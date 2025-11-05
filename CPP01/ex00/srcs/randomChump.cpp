/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:32:42 by camerico          #+#    #+#             */
/*   Updated: 2025/11/04 19:14:14 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Implémentation de la fonction void randomChump(std::string name)

//Cette fonction crée un zombie sur la STACK (variable locale), 
//appelle announce() puis le zombie est automatiquement détruit en fin de fonction

#include "Zombie.hpp"
#include <iostream>

void randomChump(std::string name)
{
	Zombie	zombie(name);		//cree sur la stack
	zombie.announce();			// on l'utilise direct

	//est detruit automatiquement avec le destructeur.ensuite le zombie n'existe plus
}