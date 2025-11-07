/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:45:57 by camerico          #+#    #+#             */
/*   Updated: 2025/11/07 19:38:35 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

// HumanA::HumanA(std::string name, Weapon& weapon)
// {
// 	this->_name = name;
// 	this->_weapon = weapon;
// }
//ou
HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}


void HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with their " 
		<< this->_weapon.getType() << std::endl;
}