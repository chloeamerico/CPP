/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:35:01 by camerico          #+#    #+#             */
/*   Updated: 2025/12/09 18:27:19 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();
	
	std::cout << std::endl;
	
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	std::cout << k->getType() << std::endl;

	std::cout << std::endl;
	
	meta->makeSound();
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	k->makeSound();

	std::cout << std::endl;
	
	delete (i);
	delete (j);
	delete (meta);
	delete (k);
	return 0;
}