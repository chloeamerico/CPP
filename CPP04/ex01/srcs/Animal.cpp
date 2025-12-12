/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:24:35 by camerico          #+#    #+#             */
/*   Updated: 2025/12/09 18:38:10 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << COLOR_GREY << "Animal constructor called" << COLOR_RESET << std::endl;
}

Animal::Animal(const Animal &copy) : _type(copy._type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& copy){
	std::cout << "Animal copy assignment operator called" << std::endl;

	if (this != &copy)
		this->_type = copy._type;
	
	return *this;
}

Animal::~Animal() {
	std::cout << COLOR_GREY << "Animal destructor called" << COLOR_RESET << std::endl;
}

//fct membres

void Animal::makeSound() const {
	std::cout << "This animal doesn't make sound" << std::endl;
}

std::string Animal::getType() const {
	
	return this->_type;
}
