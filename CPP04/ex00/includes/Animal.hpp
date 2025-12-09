/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:52:19 by camerico          #+#    #+#             */
/*   Updated: 2025/12/09 17:58:21 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

#define COLOR_BLUE "\033[34m"
#define COLOR_RED "\033[31m"
#define COLOR_GREY "\033[38;5;246m"
#define COLOR_RESET "\033[0m"

class Animal {
	
	protected :
		std::string _type;

	public :
		Animal();
		Animal(const Animal& copy);
		Animal& operator=(const Animal& copy);
		virtual ~Animal();

		virtual void makeSound() const;
		std::string getType() const;
};

#endif