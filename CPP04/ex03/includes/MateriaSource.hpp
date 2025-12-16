/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:45:33 by camerico          #+#    #+#             */
/*   Updated: 2025/12/16 19:20:57 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{

	private:
		AMateria* _materias[4];		//modeles de materias a stocker

	public:

		//forme canonique
		MateriaSource();
		MateriaSource(const MateriaSource& copy);
		MateriaSource& operator=(const MateriaSource& copy);
		virtual ~MateriaSource();


		//fonctions membres	
		virtual void learnMateria(AMateria* m);			// copie la Materia passe en param et la stock pr pouvoir la cloner plus tard. Peut connaitre jusqu'a 4 Materias
		virtual AMateria* createMateria(std::string const & type);			//renvoie une nvlle Materia copie de la Materia precedemment apprise , type est celui passe en parametre. renvoie 0 si type inconnu
};

#endif