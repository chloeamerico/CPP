/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:29:25 by camerico          #+#    #+#             */
/*   Updated: 2025/12/23 18:46:39 by camerico         ###   ########.fr       */
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
	

	// std::cout << "--------------" << std::endl;

	// try
	// {
	// 	Bureaucrat b2("jean", 4);
	// 	Form form2("form2", 5, 3);

	// 	b2.signForm(form2);
	

	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	
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