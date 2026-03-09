/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:42:44 by camerico          #+#    #+#             */
/*   Updated: 2026/03/09 18:33:52 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream> 
#include <cctype>
#include <stdexcept> //pour lqmcer l'exception
#include <list>

class RPN
{
	private :
		std::stack<double, std::list<double> > _pile;
	
	public :
	
		RPN();
		RPN(const RPN& copy);
		RPN& operator=(const RPN& copy);
		~RPN();
		
		void run(const std::string &str);
		double get_result() const;
};

#endif