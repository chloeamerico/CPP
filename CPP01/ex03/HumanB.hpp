/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:05:42 by camerico          #+#    #+#             */
/*   Updated: 2025/11/07 18:26:20 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMAN_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
	private :

	std::string _name;
	Weapon* 	_weapon;	//pointeur plus adapte car pas forcement d'arme au debut
	
	public:
	HumanB(std::string name);

	void setWeapon(Weapon& weapon);		//pour donner une arme a HumanB apres sa creation
	void attack(void) const;
};

#endif