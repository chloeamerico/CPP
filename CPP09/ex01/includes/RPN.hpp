/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:42:44 by camerico          #+#    #+#             */
/*   Updated: 2026/02/20 17:51:00 by camerico         ###   ########.fr       */
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

class RPN
{
	private :
		std::stack<double> _pile;
	
	public :
	
		RPN();
		RPN(const RPN& copy);
		RPN& operator=(const RPN& copy);
		~RPN();
		
		void run(const std::string &str);
		double get_result() const;
};

#endif