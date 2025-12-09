/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:20:40 by camerico          #+#    #+#             */
/*   Updated: 2025/12/09 17:59:02 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"


Cat::Cat() : Animal() {
	_type = "Cat";
	
	std::cout << COLOR_GREY << "Cat constructor called" << COLOR_RESET << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &copy)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	
	if (this != &copy)
		Animal::operator=(copy);
	
	return *this;
}

Cat::~Cat() {
	std::cout << COLOR_GREY << "Cat destructor called" << COLOR_RESET << std::endl;
}


void Cat::makeSound() const {
	std::cout <<  COLOR_BLUE << "Miaouuu!" << COLOR_RESET << std::endl;
}

