/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:29:25 by camerico          #+#    #+#             */
/*   Updated: 2025/12/29 11:35:29 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Bob", 160);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	std::cout << "--------------" << std::endl;

	try
	{
		Bureaucrat b2("jean", 150);
		
		std::cout << "Bureaucrat " << b2.getName() << " has grade : " << b2.getGrade() << std::endl;
		
		std::cout << b2.getName() << "'s grade increment..." << std::endl;
		b2.incrementGrade();
		std::cout << "Bureaucrat " << b2.getName() << " has grade : " << b2.getGrade() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "--------------" << std::endl;

	try
	{
		Bureaucrat b3("henry", 1);
		
		std::cout << "Bureaucrat " << b3.getName() << " has grade : " << b3.getGrade() << std::endl;
		
		std::cout << b3.getName() << "'s grade increment..." << std::endl;
		b3.incrementGrade();
		std::cout << "Bureaucrat " << b3.getName() << " has grade : " << b3.getGrade() << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "--------------" << std::endl;

	try
	{
		Bureaucrat b4("paul", 1);
		Bureaucrat b5("Emma", 3);

		std::cout << b4 << std::endl;
		b5 = b4;
		std::cout << b5 << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "--------------" << std::endl;

	try
	{
		Bureaucrat b4("paul", 1);
		Bureaucrat b5 = b4;

		std::cout << b4 << std::endl;
		b5 = b4;
		std::cout << b5 << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}