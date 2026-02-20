/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:02:05 by camerico          #+#    #+#             */
/*   Updated: 2026/01/21 11:53:16 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/Span.hpp"


//mon main

int main()
{
	try
	{
		std::cout << "--- TEST 1 ---" << std::endl;			//tout fonctionne bien

		Span sp(5);

		sp.addNumber(12);
		sp.addNumber(8);
		sp.addNumber(8);
		
		std::cout << "shortestSpan : " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan : " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "--- TEST 2 ---" << std::endl;
		
		Span sp(1);		//taille de 1 --> exception

		sp.addNumber(2);
		sp.addNumber(3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "--- TEST 3 ---" << std::endl;
		
		Span sp(19);		

		sp.addNumber(2);		//1 seul nb --> exception

		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "--- TEST 4 ---" << std::endl;
		
		Span sp(19);		

		sp.addNumber(INT_MIN);		//avec int min et int max ==> pas d'overflow
		sp.addNumber(INT_MAX);
		sp.addNumber(18);

		std::cout << "longestSpan entre INT_MIN et INT_MAX : " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "--- TEST 5 ---" << std::endl;
		
		Span sp(10000);
		std::vector<int> bigv;

		srand(time(NULL));		//test avec 10000 nb aleatoires
		for (int i = 0; i < 10000; i++)
			bigv.push_back(rand());

		sp.addNumbers(bigv.begin(), bigv.end());

		std::cout << "longestSpan entre 10 000 nb : " << sp.longestSpan() << std::endl;
		std::cout << "shortestSpan entre 10 000 nb : " << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	
}

//main du sujet :

// int main()
// {
// 	Span sp = Span(5);
	
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
	
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
	
// 	return 0;
// }