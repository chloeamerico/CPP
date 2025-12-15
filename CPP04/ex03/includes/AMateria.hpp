/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:38:31 by camerico          #+#    #+#             */
/*   Updated: 2025/12/15 19:56:28 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

class ICharacter;		//forward pour dire que cette class existe , pour eviter les warnings pour la fonction use()

class AMateria
{
	protected:
		std::string _type;
	
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& copy);
		AMateria& operator=(const AMateria& copy);
		virtual ~AMateria();
		
		
		std::string const & getType() const; //Returns the materia type / une reference plutot qu'une copie
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif