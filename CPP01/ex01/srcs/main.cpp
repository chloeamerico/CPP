/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:30:18 by camerico          #+#    #+#             */
/*   Updated: 2025/11/05 18:54:21 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

//pour creer une horde de 5 zombies avec le meme nom 
//et en appelant announce
int	main(void)
{
	int N = 5;

	std::cout << "---on cree la horde---" << std::endl << std::endl;
	
	Zombie *horde = zombieHorde(N, "chloe");
	
	if(!horde)
		return 1;
	
	std::cout << "---les zombies s'annoncent---" << std::endl << std::endl;
	
	for(int i = 0; i < N; i++)
	{
		std::cout << "Zombie " << i << " : ";
		horde[i].announce();
	}
	
	std::cout << std::endl << "---on detruit les zombies---" << std::endl << std::endl;
	
	delete[] horde;		//on libere le tableau

	return 0;
}