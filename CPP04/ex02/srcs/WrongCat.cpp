/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:22:54 by camerico          #+#    #+#             */
/*   Updated: 2025/12/09 18:23:58 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal() {
	_type = "WrongCat";
	
	std::cout << COLOR_GREY << "WrongCat constructor called" << COLOR_RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	
	if (this != &copy)
		WrongAnimal::operator=(copy);
	
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << COLOR_GREY << "WrongCat destructor called" << COLOR_RESET << std::endl;
}

// fonction membre

void WrongCat::makeSound() const {
	std::cout <<  COLOR_BLUE << "Miaouuu!" << COLOR_RESET << std::endl;
}

