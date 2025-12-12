/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:35:01 by camerico          #+#    #+#             */
/*   Updated: 2025/12/12 17:02:26 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"


//main du sujet
// int main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	delete j;//should not create a leak
// 	delete i;
	
// 	return 0;
// }

//mon main
int main()
{
	Animal* animal[4];
	
	animal[0] = new Dog();
	animal[1] = new Dog();
	animal[2] = new Cat();
	animal[3] = new Cat();

	std::cout << std::endl;

	for(int i = 0; i < 4; i++)
	{
		std::cout << animal[i]->getType() << " : ";
		animal[i]->makeSound();
	}
	
	// for(int i = 0; i < 4; i++)
	// 	animal[i]->makeSound();
	
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete animal[i];
}






// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	const WrongAnimal* k = new WrongCat();
	
// 	std::cout << std::endl;
	
// 	std::cout << j->getType() << std::endl;
// 	std::cout << i->getType() << std::endl;
// 	std::cout << k->getType() << std::endl;

// 	std::cout << std::endl;
	
// 	meta->makeSound();
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	k->makeSound();

// 	std::cout << std::endl;
	
// 	delete (i);
// 	delete (j);
// 	delete (meta);
// 	delete (k);
// 	return 0;
// }