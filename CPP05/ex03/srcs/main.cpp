/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:29:25 by camerico          #+#    #+#             */
/*   Updated: 2025/12/29 12:07:43 by camerico         ###   ########.fr       */
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
	try
	{
		Intern		intern;
		AForm 		*rrf;		//on cree un pointeur qui peut pointer vers n'importe quelle classe derivee de AForm
		Bureaucrat	bob("bob", 1);
		
		rrf = intern.makeForm("robotomy request", "Bob");
		
		if (rrf)
		{
			std::cout << *rrf << std::endl;
			bob.signForm(*rrf);
			bob.executeForm(*rrf);
			delete rrf;
		}
		else
			std::cerr << "Fail to create robotomy request form" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


}