/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:29:25 by camerico          #+#    #+#             */
/*   Updated: 2025/12/27 16:19:40 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/Bureaucrat.hpp"
#include "./../includes/AForm.hpp"
#include "./../includes/ShrubberyCreationForm.hpp"
#include "./../includes/RobotomyRequestForm.hpp"
#include "./../includes/PresidentialPardonForm.hpp"
#include "./../includes/Intern.hpp"


// choisir entre shrubbery creation , robotomy request ou presidential pardon


int main()
{
	// try
	// {
	// 	// Bureaucrat b1("Bob", 24);
	// 	Intern		intern;
	// 	AForm 		*rrf;
		
	// 	rrf = intern.makeForm("robotomy request", "Bob");
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	

	try
	{
		Intern		intern;
		AForm 		*rrf;		//on cree un pointeur qui peut pointer vers n'importe quelle classe derivee de AForm
		
		rrf = intern.makeForm("robotomy request", "Bob");
		delete rrf;
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