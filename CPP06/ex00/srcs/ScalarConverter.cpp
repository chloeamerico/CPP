/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:17:16 by camerico          #+#    #+#             */
/*   Updated: 2025/12/29 17:54:26 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ScalarConverter.hpp"
#include <cctype>		//pour isalpha

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
*/

//float = se termine par f et contient un .
static bool is_float(std::string &s)
{
	size_t i = 0;
	
	//string vide
	if (s.empty())
		return false;	
	

	//pour le signe
	if(s[i] == '+' || s[i] == '-')
	{
		//avec le signe , longueur min de 5 char (pour +0.0f)
		if (s.length() < 5)	
			return false;
	
			i++;
	}
	
	//sans le signe , longueur min 4 (pour 0.0f)
	else if (s.length() < 4)
		return false;
		
	if (!(s[i] >= '0' && s[i] <= '9'))	//premier char est un nb
		return false;

	while(i < s.length() && s[i] != '.')				//on avance jusqu'au .
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return false;
		i++;
	}
	if (i >= s.length() || s[i] != '.')				//si il n'y a pas de .
		return false;
		
	i++;	//on saute le point
	
	//si il y a au moins 1 nb apres le .
	if (i >= s.length() || !(s[i] >= '0' && s[i] <= '9'))	
		return false;

	//on avance jusqu'a ce que ce soit des chiffres
	while(i < s.length() && s[i] >= '0' && s[i] <= '9')
		i++;
	
	if (i >= s.length() || s[i] != 'f')
		return false;

	if ((i + 1) != s.length())
		return false;
	return true; 
	
}

static void ScalarConverter::convert(std::string& s)
{
	//gere les cas speciaux avant (pseudo-literals)

	if (s == "nan" || s == "nanf")
	{
		std::cout << "char : impossible" << std::endl
			<< "int : impossible" << std::endl
			<< "float : nanf" << std::endl
			<< "double : nan" << std::endl;
	}

	if (s == "+inf" || s == "+inff")
	{
		std::cout << "char : impossible" << std::endl
			<< "int : impossible" << std::endl
			<< "float : +inff" << std::endl
			<< "double : +inf" << std::endl;
	}

	if (s == "inf" || s == "inff")
	{
		std::cout << "char : impossible" << std::endl
			<< "int : impossible" << std::endl
			<< "float : inff" << std::endl
			<< "double : inf" << std::endl;
	}

	if (s == "-inf" || s == "-inff")
	{
		std::cout << "char : impossible" << std::endl
			<< "int : impossible" << std::endl
			<< "float : -inff" << std::endl
			<< "double : -inf" << std::endl;
	}


	//detecter le type

		//c'est un char
	
	if (s.length() == 1 && !isalpha(s[0]))
	{
		
	}

		//c'est un float
	
	if 
}


