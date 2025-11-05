/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:17:45 by camerico          #+#    #+#             */
/*   Updated: 2025/11/05 15:29:01 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie
{
	
	private :
	
	std::string	name;
	
	
	public :

	Zombie(std::string n);	//Constructeur
	~Zombie();				//Destructeur (doit afficher message de debug avec le nom du zombie)
	
	void announce(void);			// Methode : qui affiche <name> BraiiiiiiinnnzzzZ...
	
};

Zombie	*newZombie(std::string name);
void 	randomChump(std::string name);

#endif