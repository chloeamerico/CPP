/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_type.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:17:35 by camerico          #+#    #+#             */
/*   Updated: 2025/12/30 17:21:17 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ScalarConverter.hpp"


//float = se termine par f et contient un .
bool ScalarConverter::is_float(std::string &s)
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
bool ScalarConverter::is_double(std::string &s)
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
bool ScalarConverter::is_int(std::string &s)
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

bool ScalarConverter::is_char(std::string &s)
{
	if (s.length() != 1)
		return false;

	if (s[0] >= '0' && s[0] <= '9')
		return false;
	
	return true;
}
