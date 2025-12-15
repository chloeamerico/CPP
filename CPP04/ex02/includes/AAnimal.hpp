/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:52:19 by camerico          #+#    #+#             */
/*   Updated: 2025/12/15 14:16:13 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

#define COLOR_BLUE "\033[34m"
#define COLOR_RED "\033[31m"
#define COLOR_GREY "\033[38;5;246m"
#define COLOR_RESET "\033[0m"

class AAnimal {
	
	protected :
		std::string _type;

	public :
		AAnimal();
		AAnimal(const AAnimal& copy);
		AAnimal& operator=(const AAnimal& copy);
		virtual ~AAnimal();

		virtual void makeSound() const = 0;
		std::string getType() const;
};

#endif