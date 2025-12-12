/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:20:40 by camerico          #+#    #+#             */
/*   Updated: 2025/12/12 17:36:04 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"


Cat::Cat() : AAnimal() {
	_type = "Cat";
	_brain = new Brain();
	
	std::cout << COLOR_GREY << "Cat constructor called" << COLOR_RESET << std::endl;
}

Cat::Cat(const Cat& copy) : AAnimal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain(*copy._brain);		//on copie le brain existant dans un new brain, et (*copy._brain) pour copier aussi les ideas
}

Cat& Cat::operator=(const Cat &copy)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	
	if (this != &copy)
	{
		AAnimal::operator=(copy);
		delete _brain;
		_brain = new Brain(*copy._brain);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << COLOR_GREY << "Cat destructor called" << COLOR_RESET << std::endl;
	delete _brain;
}


void Cat::makeSound() const {
	std::cout <<  COLOR_BLUE << "Miaouuu!" << COLOR_RESET << std::endl;
}

