/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:22:17 by camerico          #+#    #+#             */
/*   Updated: 2025/12/27 16:36:03 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ShrubberyCreationForm.hpp"

/****************************
*    form canonique			*
****************************/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", "default", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if(this != &copy)
	{
		AForm::operator=(copy);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


/****************************
*   	 public methods		*
****************************/

void ShrubberyCreationForm::childExecute() const
{
	std::string name_file = getTarget() + "_shrubbery";
	
	std::ofstream file(name_file.c_str());		//C++98 pas ne prend pas en compte std::ofstream + std::string

	file << "	               ,@@@@@@@,					" << std::endl;
	file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.			" << std::endl;
	file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888&88/8o			" << std::endl;
	file << "   ,%&%%&&%&&%,@@@&@@@/@@@88&88888/88'			" << std::endl;
	file << "   %&&%&%&/%&&%@@&@@/ /@@@88888&88888'			" << std::endl;
	file << "   %&&%/ %&%%&&@@& V /@@' `88&8 `/88'			" << std::endl;
	file << "   `&%& ` /%&'    |.|        \\'|8'			" << std::endl;
	file << "       |o|        | |         | |				" << std::endl;
	file << "       |.|        | |         | |				" << std::endl;
	file << "    \\/ ._\\/_/__/  ,\\_/__\\/.  \\_//__/_		" << std::endl;

	std::cout << "File : " << name_file << " created !" << std::endl;
}


