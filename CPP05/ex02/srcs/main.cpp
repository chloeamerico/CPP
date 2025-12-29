/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:29:25 by camerico          #+#    #+#             */
/*   Updated: 2025/12/27 16:34:45 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/Bureaucrat.hpp"
#include "./../includes/AForm.hpp"
#include "./../includes/ShrubberyCreationForm.hpp"
#include "./../includes/RobotomyRequestForm.hpp"
#include "./../includes/PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Bob", 24);
		Bureaucrat b2("Lolo", 4);
		PresidentialPardonForm form_p("Laurent");

		b1.signForm(form_p);
		b2.executeForm(form_p);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	std::cout << "--------------" << std::endl;

	try
	{
		Bureaucrat b1("jean", 140);
		Bureaucrat b2("Emma", 137);
		ShrubberyCreationForm form_s("Laurent");

		b1.signForm(form_s);
		b2.executeForm(form_s);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	// std::cout << "--------------" << std::endl;

	// try
	// {
	// 	Bureaucrat b2("henry", 1);
	// 	Form form3("form3", 150, 0);
		
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	
}