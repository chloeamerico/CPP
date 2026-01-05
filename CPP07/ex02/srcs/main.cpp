/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:22:53 by camerico          #+#    #+#             */
/*   Updated: 2026/01/05 15:39:11 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/Array.hpp"

int main(void)
{
	std::cout << "----Tab vide----" << std::endl;
	
	Array<int> empty;

	std::cout << "Taile tab: " << empty.size() << std::endl << std::endl;


	std::cout << "----TEST 2----" << std::endl;
	
	Array<int> arr(5);		//on cree un tab de taille 5
	for (unsigned int i = 0; i < arr.size(); i++)		//on initialise le tab (de 10 en 10)
		arr[i] = i * 10;
	
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";

	std::cout << std::endl;
	std::cout << "size : " << arr.size() << std::endl << std::endl;

	
	std::cout << "----TEST 3 : tab const----" << std::endl;
	
	Array<int> arr2(4);
	
	arr2[0] = 100;
	arr2[1] = 200;
	arr2[2] = 300;
	arr2[3] = 400;

	const Array<int> arr3(arr2);
	
	for (unsigned int i = 0; i < arr3.size(); i++)
		std::cout << arr3[i] << " ";

	// arr3[0] = 42;		//ne fonctionne pas car arr3 est const
	
	std::cout << std::endl;
	std::cout << "size : " << arr3.size() << std::endl << std::endl;

	
	std::cout << "----TEST 4 : index superieur a la taille du tab----" << std::endl;
	
	Array<int> arr4(3);
	
	try
	{
		arr4[10] = 42;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	
	std::cout << "----TEST 5 : deep copy et operator d'assignation----" << std::endl;
	
	Array<int> arr5(3);		//on cree un tab de taille 5
	
	arr5[0] = 2;
	arr5[1] = 4;
	arr5[2] = 6;

	Array<int> arr6(2);

	arr6[0] = 12;
	arr6[1] = 13;

	arr6 = arr5;
	
	arr5[0] = 42;
	
	for (unsigned int i = 0; i < arr6.size(); i++)
		std::cout << arr6[i] << " ";

	std::cout << std::endl;
}
