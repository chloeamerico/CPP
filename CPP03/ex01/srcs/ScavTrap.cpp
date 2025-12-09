/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:55:14 by camerico          #+#    #+#             */
/*   Updated: 2025/12/09 12:01:41 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//Forme canonique

ScavTrap::ScavTrap() : ClapTrap() 
{
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " created!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
{
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << std::endl << "ScavTrap copy constructor called" << std::endl << std::endl;

}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) 
{
	std::cout << std::endl << "ScavTrap copy assignment operator called" << std::endl << std::endl;

	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scavtrap " << _name << " destroyed!" << std::endl;
}

//nv message pour attack

void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoint <= 0 || this->_energyPoint <= 0)
	{
		std::cout << "ScavTrap " << _name << " can't attack" << std::endl;
		return;
	}
	else
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
		this->_energyPoint -= 1;
	}
}


//nvlle capacite

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
