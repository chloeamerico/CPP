/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:17:45 by camerico          #+#    #+#             */
/*   Updated: 2025/11/03 19:27:31 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie
{
	
	private :
	
	std::string	name;
	
	
	public :

	Zombie();	//Constructeur
	~Zombie();	//Destructeur (doit afficher message de debug avec le nom du zombie)
	
	void announce( void );			// qui affiche <name> BraiiiiiiinnnzzzZ...
	
};

#endif