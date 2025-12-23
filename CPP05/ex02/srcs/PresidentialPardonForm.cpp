/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:22:17 by camerico          #+#    #+#             */
/*   Updated: 2025/12/23 17:48:51 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/PresidentialPardonForm.hpp"

/****************************
*    form canonique			*
****************************/

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "default", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", target, 72, 45) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if(this != &copy)
	{
		AForm::operator=(copy);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}


/****************************
*   	 public methods		*
****************************/



void PresidentialPardonForm::childExecute() const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}




