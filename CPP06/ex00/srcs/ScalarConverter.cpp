/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:17:16 by camerico          #+#    #+#             */
/*   Updated: 2025/12/29 19:42:59 by camerico         ###   ########.fr       */
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

//un . mais pas de f
static bool is_double(std::string &s)
{
	size_t i = 0;
	
	//string vide
	if (s.empty())
		return false;	

	//pour le signe
	if(s[i] == '+' || s[i] == '-')
	{
		//avec le signe , longueur min de 4 char (pour +0.0)
		if (s.length() < 4)	
			return false;
	
		i++;
	}
	
	//sans le signe , longueur min 3 (pour 0.0)
	else if (s.length() < 3)
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
	
	if (i != s.length())
		return false;

	return true; 
	
}

//que des chiffres et parfois un signe
static bool is_int(std::string &s)
{
	size_t i = 0;

	if (s.empty())
		return false;
	
	if (s[i] == '+' || s[i] == '-')
	{
		if (s.length() == 1)
			return false;		//--> pour ne pas avoir juste + ou -
		i++;
	}

	//on avance tant que c'est des chiffres
	while(i < s.length() && s[i] >= '0' && s[i] <= '9')
		i++;
	
	if (i != s.length())
		return false;
	
	return true;
}

static bool is_char(std::string &s)
{
	if (s.length() != 1)
		return false;

	if (s[0] >= '0' && s[0] <= '9')
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

	else if (s == "+inf" || s == "+inff")
	{
		std::cout << "char : impossible" << std::endl
			<< "int : impossible" << std::endl
			<< "float : +inff" << std::endl
			<< "double : +inf" << std::endl;
	}

	else if (s == "inf" || s == "inff")
	{
		std::cout << "char : impossible" << std::endl
			<< "int : impossible" << std::endl
			<< "float : inff" << std::endl
			<< "double : inf" << std::endl;
	}

	else if (s == "-inf" || s == "-inff")
	{
		std::cout << "char : impossible" << std::endl
			<< "int : impossible" << std::endl
			<< "float : -inff" << std::endl
			<< "double : -inf" << std::endl;
	}


	//detecter le type

		//c'est un char
	
	else if (is_char(s) == true)
	{
		char c = s[0];
		
		std::cout << "char : '" << c << "'" << std::endl
			<< "int : " << static_cast<int>(s) << std::endl
			<< "float : " << static_cast<float>(s) << std::endl
			<< "double : " << static_cast<double>(s) << std::endl;
	}

		//c'est un float
	
	else if (is_float(s) == true)
	{
		float f = std::atof(s.c_str());

		std::cout << "char : " << static_cast<char>(f) << std::endl
			<< "int : " << static_cast<int>(f) << std::endl
			<< "float : " << f << std::endl
			<< "double : " << static_cast<double>(f) << std::endl;
	}

		//c'est un double ( un . sans 'f')

	else if (is_double(s) == true)
	{
		double d = atof(s.c_str());

		std::cout << "char : " << static_cast<char>(d) << std::endl
			<< "int : " << static_cast<int>(d) << std::endl
			<< "float : " << static_cast<int>(d) << std::endl
			<< "double : " << d << std::endl;
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
			std::cout << "char: not printable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

		std::cout << "int: " << i << std::endl
			<< "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl
			<< "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
	}
	 
}


