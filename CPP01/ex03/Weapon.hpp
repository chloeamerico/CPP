/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:41:04 by camerico          #+#    #+#             */
/*   Updated: 2025/11/07 17:58:58 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WAEPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	
	private :

	std::string	_type;

	public :
	
	Weapon(std::string type);		//constructeur
	
	const std::string getType(void) const;		//retourne une reference constante sur type
	void setType(std::string type); 		//attribue à type la nouvelle valeur passée en paramètre
};


#endif