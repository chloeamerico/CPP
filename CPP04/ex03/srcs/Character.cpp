/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:25:14 by camerico          #+#    #+#             */
/*   Updated: 2025/12/16 18:42:28 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


//forme canonique

Character::Character() : _name("default")
{	
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string const & name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& copy) : _name(copy._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		
		for (int i = 0; i < 4; i++)
		{
			if (copy._inventory[i])
			{
				if (this->_inventory[i])
					delete this->_inventory[i];
				this->_inventory[i] = copy._inventory[i]->clone();
			}
			else
			{
				if (this->_inventory[i])
					delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}


//fonctions membres

std::string const & Character::getName() const
{
	return this->_name;
}

//Équipe les Materias dans le premier slot vide, si plein, ne fait rien
void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4 i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return;
		}
	}
}

//Retire la Materia du slot idx mais NE LA DELETE PAS ! Si idx invalide ou slot vide, ne fait rien
void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || _inventory[idx] == NULL)
		return;
	
	_inventory[idx] = NULL;
}

//Utilise la Materia du slot idx sur la cible. Si idx invalide ou slot vide, ne fait rien
void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || _inventory[idx] == NULL)
		return;

	this->_inventory[idx]->use(target);
}
