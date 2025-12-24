/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:22:17 by camerico          #+#    #+#             */
/*   Updated: 2025/12/23 17:48:51 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/RobotomyRequestForm.hpp"

/****************************
*    form canonique			*
****************************/

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "default", 25, 5) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if(this != &copy)
	{
		AForm::operator=(copy);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}


/****************************
*   	 public methods		*
****************************/

void RobotomyRequestForm::childExecute() const
{
	std::cout << "Drilling noises : .... BBBBRRRRRRrrrr..." << std::endl;

	if(rand() % 2)
		std::cout << getTarget() << " : has been robotomized successfully !" << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}
