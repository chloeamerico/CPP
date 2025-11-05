/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:38:41 by camerico          #+#    #+#             */
/*   Updated: 2025/11/05 19:01:37 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>


//constructeur par defaut

Zombie::Zombie () {}

//destruteur

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " has been destroyed" << std::endl;
}

//fonction announce

void	Zombie::announce()
{
	std::cout << this->name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setname(std::string n)
{
	this->name = n;
}