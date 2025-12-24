/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:22:17 by camerico          #+#    #+#             */
/*   Updated: 2025/12/23 18:37:00 by camerico         ###   ########.fr       */
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

	file << "	               ,@@@@@@@,					";
	file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.			";
	file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888&88/8o			";
	file << "   ,%&%%&&%&&%,@@@&@@@/@@@88&88888/88'			";
	file << "   %&&%&%&/%&&%@@&@@/ /@@@88888&88888'			";
	file << "   %&&%/ %&%%&&@@& V /@@' `88&8 `/88'			";
	file << "   `&%& ` /%&'    |.|        \\'|8'			";
	file << "       |o|        | |         | |				";
	file << "       |.|        | |         | |				";
	file << "    \\/ ._\\/_/__/  ,\\_/__\\/.  \\_//__/_		";

	std::cout << "File : " << name_file << " created !" << std::endl;
}


