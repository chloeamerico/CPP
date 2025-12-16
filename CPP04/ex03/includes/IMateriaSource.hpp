/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:25:13 by camerico          #+#    #+#             */
/*   Updated: 2025/12/16 16:33:20 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP


#include <string>

class AMateria;

class IMateriaSource
{
		public:

			virtual ~IMateriaSource() {}
			virtual void learnMateria(AMateria*) = 0;			// copie la Materia passe en param et la stock pr pouvoir la cloner plus tard. Peut connaitre jusqu'a 4 Materias
			virtual AMateria* createMateria(std::string const & type) = 0;			//renvoie une nvlle Materia copie de la Materia precedemment apprise , type est celui passe en parametre. renvoie 0 si type inconnu

};

#endif