/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 20:22:00 by camerico          #+#    #+#             */
/*   Updated: 2025/12/09 17:48:17 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public :
		Dog();
		Dog(const Dog &copy);
		Dog& operator=(const Dog &copy);
		~Dog();

		void makeSound() const;
};

#endif