/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:57:14 by camerico          #+#    #+#             */
/*   Updated: 2025/12/05 17:08:24 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

//Forme canonique

FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 300;
	std::cout << "FragTrap " << name << " created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << std::endl << "FragTrap copy constructor called" << std::endl << std::endl;

}

FragTrap& FragTrap::operator=(const FragTrap& other) 
{
	std::cout << std::endl << "FragTrap copy assignment operator called" << std::endl << std::endl;

	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destroyed!" << std::endl;
}

//nv message pour attack

// void FragTrap::attack(const std::string& target)
// {
// 	if (this->_hitPoint <= 0 || this->_energyPoint <= 0)
// 	{
// 		std::cout << "FragTrap " << _name << " can't attack" << std::endl;
// 		return;
// 	}
// 	else
// 	{
// 		std::cout << "FragTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
// 		this->_energyPoint -= 1;
// 	}
// }


//nvlle capacite

void FragTrap::highFivesGuys(void)
{
	std::cout << "Wanna high-fives ?" << std::endl;
}
