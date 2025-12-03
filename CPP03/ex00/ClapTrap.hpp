/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:28:39 by camerico          #+#    #+#             */
/*   Updated: 2025/12/03 17:19:39 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>


class ClapTrap {
	
	private :
	std::string _name;
	int			_hitPoint;		//point de vie
	int			_energyPoint;	//point d'energie
	int			_attackDamage;	//dommages infliges en attaquant


	public :
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap ();
	
	void attack(const std::string& target);		//utilise 1 pt d'energie
	void takeDamage(unsigned int amount);		//fait perdre des points de vie
	void beRepaired(unsigned int amount);		//utilise 1 pt d'energie
	
	int get_energy(void) const;
	int get_lifepoints(void) const;

};

#endif