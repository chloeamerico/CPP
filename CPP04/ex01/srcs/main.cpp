/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:35:01 by camerico          #+#    #+#             */
/*   Updated: 2025/12/12 19:41:55 by camerico         ###   ########.fr       */
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





// mon main
int main()
{
	Animal* animal[5];
	
	animal[0] = new Dog();
	animal[1] = new Dog();
	animal[2] = new Cat();
	animal[3] = new Cat();
	animal[4] = new Animal();

	std::cout << std::endl;

	for(int i = 0; i < 5; i++)
	{
		std::cout << animal[i]->getType() << " : ";
		animal[i]->makeSound();
	}
	
	// for(int i = 0; i < 4; i++)
	// 	animal[i]->makeSound();
	
	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
		delete animal[i];
}




// //main pour set les ideas
// int main()
// {
// 	Cat cat1;
// 	Cat cat2;

// 	std::cout << std::endl;

// 	cat1.getBrain()->setIdeas("idea1");
// 	cat1.getBrain()->printIdeas();

// 	std::cout << std::endl;
	
// 	cat2 = cat1;
// 	cat2.getBrain()->printIdeas();
// }

