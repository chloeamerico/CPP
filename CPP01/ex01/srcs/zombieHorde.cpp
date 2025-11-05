/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:53:26 by camerico          #+#    #+#             */
/*   Updated: 2025/11/05 18:36:33 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//faire la fonction Zombie* zombieHorde( int N, std::string name );
/*La fonction doit:

    Allouer N objets Zombie en une seule allocation avec new
    Initialiser chaque zombie avec le même nom
    Retourner un pointeur vers le premier zombie*/


#include "Zombie.hpp"

//fait pour initialiser chaque zombie
Zombie *zombieHorde(int N, std::string name)
{
	if (N <= 0)
        return NULL;

    //on alloue les N zombies en appelant le constructeur par defaut
    Zombie *horde = new Zombie[N];

    //on initialise les N zombies avec le meme nom
    for (int i = 0; i < N; i++)
    {
        horde[i].setname(name);     //on appelle setname sur chaque zombie;
    }

    return horde;       //on return le pointeur sur le tab
}