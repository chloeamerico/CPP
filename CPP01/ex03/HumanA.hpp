/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:58:12 by camerico          #+#    #+#             */
/*   Updated: 2025/11/07 18:05:27 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string.hpp>

class HumanA
{
	private :

	std::string _name;
	Weapon&		_weapon;		//reference plus adaptee ici

	public :

	HumanA(std::string name, Weapon& weapon);	//constructeur
	void attacks(void) const;					//const car elle ne modifie pas l'etat de l'obj
};

#endif