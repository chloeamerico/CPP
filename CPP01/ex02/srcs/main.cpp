/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:05:45 by camerico          #+#    #+#             */
/*   Updated: 2025/11/07 15:33:42 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//pour travailler les pointeurs et references

#include <string>
#include <iostream>

int	main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "adresse de la string en mémoire : " << &str << std::endl;
	std::cout << "adresse stockée dans stringPTR : " << stringPTR << std::endl; 
	std::cout << "adresse stockée dans stringREF : " << &stringREF << std::endl << std::endl; 

	std::cout << "valeur de la string : " << str << std::endl;
	std::cout << "La valeur pointée par stringPTR : " << *stringPTR << std::endl; 
	std::cout << "La valeur pointée par stringREF : " << stringREF << std::endl; 

	
	return 0;
	
}



	// std::cout << stringPTR << std::endl;
	// std::cout << &stringPTR << std::endl;
	// std::cout << &str << std::endl; 
	// std::cout << *stringPTR << std::endl << std::endl; 
	
	// std::cout << stringREF << std::endl;
	// std::cout << &stringREF << std::endl;
	// std::cout << &str << std::endl; 
	// std::cout << str << std::endl; 