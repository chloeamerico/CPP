/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:07:59 by camerico          #+#    #+#             */
/*   Updated: 2025/12/16 19:36:30 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._materias[i])
			_materias[i] = copy._materias[i]->clone();
		else
			_materias[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy)
{
	if (this != &copy)
	{		
		for (int i = 0; i < 4; i++)
		{
			if (copy._materias[i])
			{
				if (this->_materias[i])
					delete this->_materias[i];
				this->_materias[i] = copy._materias[i]->clone();
			}
			else
			{
				if (this->_materias[i])
					delete this->_materias[i];
				this->_materias[i] = NULL;
			}
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if(_materias[i])
			delete _materias[i];
	}
}

// copie la Materia passe en param et la stock pr pouvoir la cloner plus tard. Peut connaitre jusqu'a 4 Materias
//deepcopy ave clone
void MateriaSource::learnMateria(AMateria* m)
{
	if(!m)
		return;
	
	for (int i = 0; i < 4; i++)
	{
		if(_materias[i] == NULL)
		{
			_materias[i] = m->clone();
			return;
		}
	}
}

//renvoie une nvlle Materia copie de la Materia precedemment apprise , type est celui passe en parametre. renvoie 0 si type inconnu
//si plusieurs materias du type passe en param sont trouvees, on renvoie la premiere
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i] != NULL && type == _materias[i]->getType())
			return _materias[i]->clone();
	}
	return NULL;
}