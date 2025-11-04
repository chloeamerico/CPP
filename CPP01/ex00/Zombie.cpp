/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:22:01 by camerico          #+#    #+#             */
/*   Updated: 2025/11/04 19:32:25 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Comprendre quand allouer le la HEAP (tas) ou sur la STACK (pile)
//ici on implemente la classe Zombie (constructeur , destructeur, et la fonction void announce( void ))

#include "Zombie.hpp"
#include <iostream>

//Constructeur

Zombie::Zombie(std::string n)
{
	this->name = n;
}

//Destructeur

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " destroyed" << std::endl;
}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}