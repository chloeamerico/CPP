/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:13:58 by camerico          #+#    #+#             */
/*   Updated: 2025/12/09 18:39:03 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << COLOR_GREY << "WrongAnimal constructor called" << COLOR_RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : _type(copy._type) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy){
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;

	if (this != &copy)
		this->_type = copy._type;
	
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << COLOR_GREY << "WrongAnimal destructor called" << COLOR_RESET << std::endl;
}

//fct membres

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal : This animal doesn't make sound" << std::endl;
}

std::string WrongAnimal::getType() const {
	
	return this->_type;
}
