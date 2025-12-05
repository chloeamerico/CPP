/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:39:56 by camerico          #+#    #+#             */
/*   Updated: 2025/12/05 12:42:25 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"


//constructeur par default
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " created!" << std::endl;
}

//constructeur de recopie
ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << std::endl << "ClapTrap copy constructor called" << std::endl << std::endl;


	_name = other._name;
	_hitPoint = other._hitPoint;
	_energyPoint = other._energyPoint;
	_attackDamage = other._attackDamage;

	// OU JUSTE
	// *this = other;
}

//Constructeur d'affectation
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << std::endl << "ClapTrap copy assignment operator called" << std::endl << std::endl;

	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoint = other._hitPoint;
		this->_energyPoint = other._energyPoint;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroyed!" << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoint <= 0 || this->_energyPoint <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack" << std::endl;
		return;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
		this->_energyPoint -= 1;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap take " << amount << " damage points on their _hitPoint" << std::endl;
	_hitPoint -= amount;
	if (_hitPoint < 0)
		_hitPoint = 0;			//on remet a 0 si _hitPoint est negatif
}

//utilise 1 pt d'energie
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoint <= 0 || this->_energyPoint <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't be repaired" << std::endl;
		return;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " repaired " << amount << " life points" << std::endl;
		_hitPoint += amount;
		_energyPoint -= 1;
	}
}