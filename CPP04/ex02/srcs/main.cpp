/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:35:01 by camerico          #+#    #+#             */
/*   Updated: 2025/12/15 14:19:41 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/AAnimal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"


//main du sujet
// int main()
// {
// 	const AAnimal* j = new Dog();
// 	const AAnimal* i = new Cat();

// 	delete j;//should not create a leak
// 	delete i;
	
// 	return 0;
// }





// mon main
int main()
{
	AAnimal* animal[4];
	
	animal[0] = new Dog();
	animal[1] = new Dog();
	animal[2] = new Cat();
	animal[3] = new Cat();
	// animal[3] = new AAnimal();

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

