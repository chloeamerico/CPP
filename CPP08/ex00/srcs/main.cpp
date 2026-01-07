/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:48:36 by camerico          #+#    #+#             */
/*   Updated: 2026/01/07 19:46:50 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>


int main(void)
{
	//test avec des vecteurs
	
	std::cout << "---- TEST VECTEURS ----" << std::endl;
	
	std::vector<int> vec;

	for (int i = 1; i < 3; i++)
	{
		vec.push_back(i);
	}
	
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 2);
		std::cout << "Found : " << *it << std::endl;	//affiche 2
	
		easyfind(vec, 42);		//ca va lancer une exception
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "42 not found" << std::endl;
	}

	std::cout << std::endl;


	std::cout << "---- TEST LIST ----" << std::endl;

	std::list<int> lst;

	for (int i = 0; i < 4; i++)
	{
		lst.push_back(i * 10);
	}
	
	try
	{
		std::list<int>::iterator it2 = easyfind(lst, 20);
		std::cout << "Found : " << *it2 << std::endl;	//affiche 2
	
		easyfind(lst, 42);		//ca va lancer une exception
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "number not found" << std::endl;
	}
	
}