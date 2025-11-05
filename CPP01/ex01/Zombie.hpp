/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:34:07 by camerico          #+#    #+#             */
/*   Updated: 2025/11/05 19:01:32 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class	Zombie
{
	private :

	std::string name;

	
	public :
	
	Zombie();
	~Zombie();

	void	announce(void);
	void	setname(std::string n);
};


Zombie* zombieHorde( int N, std::string name );

#endif