/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:32:33 by camerico          #+#    #+#             */
/*   Updated: 2025/11/04 19:09:05 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Implementation de la fonction Zombie* newZombie(std::string name)
//Cette fonction crée un zombie sur le HEAP avec new et le retourne

#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie(std::string name)
{
	Zombie	*zombie = new Zombie(name);			//<-- alloue sur la heap
	return zombie;								//on retourne le pointeur
}