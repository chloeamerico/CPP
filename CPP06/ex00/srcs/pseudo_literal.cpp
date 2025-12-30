/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo_literal.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:24:49 by camerico          #+#    #+#             */
/*   Updated: 2025/12/30 17:20:58 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ScalarConverter.hpp"
#include <climits>

bool ScalarConverter::pseudo_literal(std::string &s)
{
	if (s == "nan" || s == "nanf")
	{
		std::cout << "char : impossible" << std::endl
			<< "int : impossible" << std::endl
			<< "float : nanf" << std::endl
			<< "double : nan" << std::endl;
		
		return true;
	}

	if (s == "+inf" || s == "+inff")
	{
		std::cout << "char : impossible" << std::endl
			<< "int : impossible" << std::endl
			<< "float : +inff" << std::endl
			<< "double : +inf" << std::endl;
		
		return true;
	}

	if (s == "inf" || s == "inff")
	{
		std::cout << "char : impossible" << std::endl
			<< "int : impossible" << std::endl
			<< "float : inff" << std::endl
			<< "double : inf" << std::endl;
		
		return true;
	}

	if (s == "-inf" || s == "-inff")
	{
		std::cout << "char : impossible" << std::endl
			<< "int : impossible" << std::endl
			<< "float : -inff" << std::endl
			<< "double : -inf" << std::endl;
		
		return true;
	}
	return false;
}