/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:20:20 by camerico          #+#    #+#             */
/*   Updated: 2025/11/07 19:40:02 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack(void) const
{
	if (this->_weapon == NULL)
	{
		std::cout << this->_name << " has no weapon" << std::endl;
		return;
	}
	std::cout << this->_name << " attacks with their " 
		<< this->_weapon->getType() << std::endl;
}