/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:09:08 by camerico          #+#    #+#             */
/*   Updated: 2025/12/09 18:12:15 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGWrongANIMAL_HPP
#define WRONGWrongANIMAL_HPP

#include <string>
#include <iostream>

#define COLOR_BLUE "\033[34m"
#define COLOR_RED "\033[31m"
#define COLOR_GREY "\033[38;5;246m"
#define COLOR_RESET "\033[0m"

class WrongAnimal {
	
	protected :
		std::string _type;

	public :
		WrongAnimal();
		WrongAnimal(const WrongAnimal& copy);
		WrongAnimal& operator=(const WrongAnimal& copy);
		virtual ~WrongAnimal();

		void makeSound() const;
		std::string getType() const;
};

#endif