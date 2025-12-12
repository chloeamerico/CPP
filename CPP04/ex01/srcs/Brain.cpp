/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:35:16 by camerico          #+#    #+#             */
/*   Updated: 2025/12/12 19:38:01 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//forme canonique

Brain::Brain() {
	for (int i = 0 ; i < 100 ; i++)
		_ideas[i] = "";
	
	std::cout << COLOR_GREY << "Brain constructor called" << COLOR_RESET<< std::endl;
}

Brain::Brain(const Brain& copy)
{
	std::cout << "Brain copy constructor called" << std::endl;

	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
}

Brain& Brain::operator=(const Brain& copy)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	
	if (this != &copy)
	{
		for (int i = 0 ; i < 100 ; i++)
			this->_ideas[i] = copy._ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << COLOR_GREY << "Brain destructor called" << COLOR_RESET << std::endl;
}

//public methods

void Brain::setIdeas(const std::string idea)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = idea;
}
void Brain::printIdeas() const
{
	for (int i = 0; i < 100; i++)
		std::cout << this->_ideas[i] << std::endl;
}
