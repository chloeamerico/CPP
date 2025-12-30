/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:17:16 by camerico          #+#    #+#             */
/*   Updated: 2025/12/30 18:29:02 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ScalarConverter.hpp"
#include <cctype>		//pour isalpha
#include <climits>		//pour les limits

//form canonique (seulemt destructeur)

ScalarConverter::~ScalarConverter() {}


/* La fonction Convert doit : 
	- prendre une string en param
	- detecter le type de la variable passee en param (un char, int, float ou double)
	- convertir la string vers son type reel
	- convertir cette valeur vers les 3 autres types
	- afficher les 4 resultats
*/

/*	A gerer (exceptions pseudo-literals):

	==> "Not A Number", pour representer un resultat invalide (ex /0...)
		- nan(double)
		- nanf(float)

	==> "Infini"
	- "inf" -> double / positif
	- "inff" -> float / positif
	- "+inf" -> double / positif
	- "+inff" -> float / positif
	- "-inf" -> double / negatif
	- "-inff" -> float / degatif


ATTENTION , en C++, pas de !str[i] mais , if(i >= str.length())

	pour convertir une string vers sa valeur reelle , on utilise :
		- std::atoi() pour un int
		- std::atof() pour un float/double
		- s[0] directement pour un char 
	
	c_str() est une methode qui retourne un pointeur vers une chaine de char c termine par un char nul.
	permet de passer un estd::string a des fonctions de C

	
ATTENTION : quand on converti en float, il est bien stocke en memoire le nombre en float (ex 42.0f) mais std::cout n'affiche pas de decimales.
penser a bien rajouter le .0f

ou utiliser :  std::setprecision(n)
utilise tout seul, il affiche n char au total
mais avec std::fixed , n devient le nb de chiffres affiches apres la virgule :
ex : 
std::cout << std::fixed << std::setprecision(1) << num;  // Affiche "42.0"

*/


void ScalarConverter::convert(std::string s)
{
	//gere les cas speciaux avant (pseudo-literals)

	if (pseudo_literal(s) == true)
		return;


	//detecter le type

		//c'est un char
	
	else if (is_char(s) == true)
	{
		char c = s[0];
		
		std::cout << "char: '" << c << "'" << std::endl
			<< "int: " << static_cast<int>(c) << std::endl
			<< "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl
			<< "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
	}

		//c'est un float
	
	else if (is_float(s) == true)
	{
		double d = std::atof(s.c_str());		//atof converti un char en double, il faut ensuite le cast en float

		float f = static_cast<float>(d);

		if (std::isinf(f) || fabs(f) > 1e308)
		{
			std::cout << "char: impossible" << std::endl
				<< "int: impossible" << std::endl
				<< "float: " << (f > 0 ? "+inff" : "-inff") << std::endl
				<< "double: " << (d > 0 ? "+inf" : "-inf") << std::endl;
			return;
	    }

		if (f < 0 || f > 127 || f != static_cast<int>(f))
			std::cout << "char: impossible" << std::endl;
		else if (!isprint(static_cast<char>(f)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

		if (f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN))
			std::cout <<  "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(f) << std::endl;
	
		
		std::cout << "float: " << std::fixed << std::setprecision(1) 
			<< f << "f" << std::endl;

		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
	}

		//c'est un double ( un . sans 'f')

	else if (is_double(s) == true)
	{
		double d = std::atof(s.c_str());

		if (std::isinf(d) || d > DBL_MAX || d < -DBL_MAX)
		{
			std::cout << "char: impossible" << std::endl
				<< "int: impossible" << std::endl
				<< "float: " << (d > 0 ? "+inff" : "-inff") << std::endl
				<< "double: " << (d > 0 ? "+inf" : "-inf") << std::endl;
			return;
		}
		
		if (d < 0 || d > 127 || d != static_cast<int>(d))
			std::cout << "char: impossible" << std::endl;
		else if (!isprint(static_cast<char>(d)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

		if (d > INT_MAX || d < INT_MIN)
			std::cout <<  "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;
	
		
		std::cout << "float: " << std::fixed << std::setprecision(1) 
			<< static_cast<float>(d) << "f" << std::endl;

		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;


	}

		//c'est un int
	
	else if (is_int(s) == true)
	{
		long l = std::atol(s.c_str());

		//verif si ca depasse les limites du int 
		if (l > INT_MAX || l < INT_MIN)
		{
			std::cout << "char: impossible" << std::endl
				<< "int: impossible" << std::endl
				<< "float: impossible" << std::endl
				<< "double: impossible" << std::endl;
    	    return;
		}
		
		int i = static_cast<int>(l);
		
		if (i < 0 || i > 127)
			std::cout << "char: impossible" << std::endl;
		else if (!isprint(static_cast<char>(i)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

		std::cout << "int: " << i << std::endl
			<< "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl
			<< "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
	}
	else
	{
		std::cerr << "You must write either a char (ex: a), an int (ex: 42), a double (ex: 42.0), or a float (ex: 42.0f) as a parameter." << std::endl;
	}
	 
}


