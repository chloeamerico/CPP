/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:53:35 by camerico          #+#    #+#             */
/*   Updated: 2025/12/12 19:36:49 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal() {
	_type = "Dog";
	_brain = new Brain();
	
	std::cout << COLOR_GREY << "Dog constructor called" << COLOR_RESET << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*copy._brain);
}

Dog& Dog::operator=(const Dog &copy)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	
	if (this != &copy)
	{
		Animal::operator=(copy);
		delete _brain;
		_brain = new Brain(*copy._brain);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << COLOR_GREY << "Dog destructor called" << COLOR_RESET << std::endl;
	
	delete _brain;
}


void Dog::makeSound() const {
	std::cout << COLOR_RED << "Wouafff!" << COLOR_RESET << std::endl;
}

Brain *Dog::getBrain() const
{
	return (this->_brain);
}