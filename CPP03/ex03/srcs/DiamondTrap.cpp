/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:24:22 by camerico          #+#    #+#             */
/*   Updated: 2025/12/09 12:05:29 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

// c'est DiamondTrap qui construit ClapTrap
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
	ScavTrap(name), FragTrap(name)
{
	this->_name = name; 	//on initialise le _name de DT

	_hitPoint = FragTrap::_hitPoint;
	_energyPoint = 50;
	_attackDamage = FragTrap::_attackDamage;
	
	std::cout << "DiamondTrap " << this->_name << " created!" << std::endl << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other),
	FragTrap(other)
{
	this->_name = other._name;		//copie le _name de DT
	
	std::cout << std::endl << "DiamondTrap copy constructor called" << std::endl << std::endl;
}

//on doit appeler les operator = de toutes les classes parentes pour copier correctement tous les attributs
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << std::endl << "DiamondTrap copy assignment operator called" << std::endl << std::endl;

	if (this != &other)
	{
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		ClapTrap::operator=(other);
		this->_name = other._name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " destroyed!" << std::endl;
}


void DiamondTrap::whoAmI()
{
	std::cout << std::endl << "My name is " << this->_name << std::endl;		//nom de DiamondTrap::_name
	std::cout << "My ClapTrap name is " << ClapTrap::_name << std::endl << std::endl;	//nom de ClapTrap::_name
}
