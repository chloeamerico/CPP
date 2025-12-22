/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:29:25 by camerico          #+#    #+#             */
/*   Updated: 2025/12/22 17:58:14 by camerico         ###   ########.fr       */
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
		Bureaucrat b2("henry", 1);
		
		std::cout << "Bureaucrat " << b2.getName() << " has grade : " << b2.getGrade() << std::endl;
		
		std::cout << b2.getName() << "'s grade increment..." << std::endl;
		b2.incrementGrade();
		std::cout << "Bureaucrat " << b2.getName() << " has grade : " << b2.getGrade() << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}