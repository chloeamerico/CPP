/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:02:36 by camerico          #+#    #+#             */
/*   Updated: 2025/12/30 17:32:36 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype> 	 // pour is_print ou is_alpha
#include <climits>   // pour INT_MAX, INT_MIN
#include <iomanip>   // pour std::fixed et std::setprecision
#include <iostream>  // pour std::cout
#include <cstdlib>   // pour atoi, atol, atof

class ScalarConverter {

	private :
	
		//constructeurs en private pour rendre la class non instanciable

		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& copy);
		
		//detect_type
		static bool is_float(std::string &s);
		static bool is_double(std::string &s);
		static bool is_int(std::string &s);
		static bool is_char(std::string &s);
		static bool pseudo_literal(std::string &s);
		

	public :
		
		/*destructeur peut etre en prive ou en public peut importe , il ne sera jamais
		appele car les construct sont en public et la classe est non instanciable*/
		
		~ScalarConverter();

		//public methods

		static void convert(std::string s);

};


#endif