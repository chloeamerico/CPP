/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:00:44 by camerico          #+#    #+#             */
/*   Updated: 2025/12/16 17:38:53 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{

	private:

		AMateria* _inventory[4];
		std::string	_name;

	public:

		//forme canonique
		Character();
		Character(std::string const & name);
		Character(const Character& copy);
		Character& operator=(const Character& copy);
		virtual ~Character();

		//fonctions membres
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);		//Équipe les Materias dans le premier slot vide, si plein, ne fait rien
		virtual void unequip(int idx);			//Retire la Materia du slot idx mais NE LA DELETE PAS ! Si idx invalide ou slot vide, ne fait rien
		virtual void use(int idx, ICharacter& target);		//Utilise la Materia du slot idx sur la cible. Si idx invalide ou slot vide, ne fait rien
};

#endif


//Les Materias doivent être supprimées quand un Character est détruit
//L'inventaire est vide à la construction