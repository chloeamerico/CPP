/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 21:09:32 by camerico          #+#    #+#             */
/*   Updated: 2026/01/03 16:19:43 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/iter.hpp"

/* sizeof :
	- dans notre cas, pour un tab de 4 int, sizeof(tab) = 20. car 5 (elements) x 4 (octets)
	- donc size(tab) / sizeof(tab[0]) = 5 ==> la taille du tab
*/

template <typename T>			//test avec un template
void afficher(const T& n)		//test avec const
{
	std::cout << n << " ";
}

//fonction qui incremente chaque elemetn du tab
template <typename T>	
void increment(T& n)			//test sans const
{
	n++;
}

int main(void)
{

	//test avec des int
	
	int tab1[] = {0, 1, 2, 3, 4};
	
	size_t lenght1 = sizeof(tab1) / sizeof(tab1[0]);
	
	std::cout << "------ TEST INT------" << std::endl;
	std::cout << "test avant d'incementer :";
	iter(tab1, lenght1, afficher<int>);
	iter(tab1, lenght1, increment<int>);
	std::cout << std::endl << "test apres d'incementer :";
	iter(tab1, lenght1, afficher<int>);

	std::cout << std::endl << std::endl;
	
	//test avec des doubles

	double tab2[] = {0.1, 1.1, 2.2, 3.3, 4.4};
	
	size_t lenght2 = sizeof(tab2) / sizeof(tab2[0]);
	
	std::cout << "------ TEST DOUBLE------" << std::endl;
	std::cout << "test avant d'incementer :";
	iter(tab2, lenght2, afficher<double>);
	iter(tab2, lenght2, increment<double>);
	std::cout << std::endl << "test apres d'incementer :";
	iter(tab2, lenght2, afficher<double>);

	std::cout << std::endl << std::endl;
	
	//test avec des char

	char tab3[] = {'a', 'c'};
	
	size_t lenght3 = sizeof(tab3) / sizeof(tab3[0]);
	
	std::cout << "------ TEST CHAR------" << std::endl;
	std::cout << "test avant d'incementer :";
	iter(tab3, lenght3, afficher<char>);
	iter(tab3, lenght3, increment<char>);
	std::cout << std::endl << "test apres d'incementer :";
	iter(tab3, lenght3, afficher<char>);

	std::cout << std::endl;
	
	return 0;

}

