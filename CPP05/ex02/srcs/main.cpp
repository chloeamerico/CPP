/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:29:25 by camerico          #+#    #+#             */
/*   Updated: 2025/12/23 13:49:42 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/Bureaucrat.hpp"
#include "./../includes/Form.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Bob", 130);
		Form form1("form1", 5, 3);

		b1.signForm(form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	std::cout << "--------------" << std::endl;

	try
	{
		Bureaucrat b2("jean", 4);
		Form form2("form2", 5, 3);

		b2.signForm(form2);
	

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "--------------" << std::endl;

	try
	{
		Bureaucrat b2("henry", 1);
		Form form3("form3", 150, 0);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}