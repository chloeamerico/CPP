/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:03:44 by camerico          #+#    #+#             */
/*   Updated: 2025/12/12 19:37:32 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

#define COLOR_GREY "\033[38;5;246m"
#define COLOR_RESET "\033[0m"


class Brain {

	private :
		std::string _ideas[100];
	
	public :
		Brain();
		Brain(const Brain& copy);
		Brain& operator=(const Brain& copy);
		~Brain();
		
		void setIdeas(const std::string idea);
		void printIdeas() const;
};

#endif