/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:02:36 by camerico          #+#    #+#             */
/*   Updated: 2025/12/27 18:56:33 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter {

	private :
	
	//constructeurs en private pour rendre la class non instanciable

	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter& operator=(const ScalarConverter& copy);


	public :
	
	/*destructeur peut etre en prive ou en public peut importe , il ne sera jamais
	appele car les construct sont en public et la classe est non instanciable*/
	
	~ScalarConverter();

	//public methods

	static void convert(std::string s);

}


#endif