/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:24:35 by camerico          #+#    #+#             */
/*   Updated: 2025/12/09 18:38:10 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
	std::cout << COLOR_GREY << "AAnimal constructor called" << COLOR_RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) : _type(copy._type) {
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& copy){
	std::cout << "AAnimal copy assignment operator called" << std::endl;

	if (this != &copy)
		this->_type = copy._type;
	
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << COLOR_GREY << "AAnimal destructor called" << COLOR_RESET << std::endl;
}

//fct membres

void AAnimal::makeSound() const {
	std::cout << "This Aanimal doesn't make sound" << std::endl;
}

std::string AAnimal::getType() const {
	
	return this->_type;
}
