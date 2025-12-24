/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:19:00 by camerico          #+#    #+#             */
/*   Updated: 2025/12/23 18:22:54 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/AForm.hpp"

/****************************
*    form canonique			*
****************************/

AForm::AForm() : _name("Default"), _is_signed(0), _required_grade_to_sign(150),
			_required_grade_to_execute(150), _target("Default") {}

AForm::AForm(std::string name, std::string target, const int required_grade_to_sign, const int required_grade_to_execute) :
			_name(name), _is_signed(false),
			_required_grade_to_sign(required_grade_to_sign), 
			_required_grade_to_execute(required_grade_to_execute),
			_target(target)
{
	if (required_grade_to_sign > 150 || required_grade_to_execute > 150)
		throw GradeTooLowException();
	if (required_grade_to_sign < 1 || required_grade_to_execute < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& copy) : _name(copy._name), _is_signed(copy._is_signed), 
	_required_grade_to_sign(copy._required_grade_to_sign),
	_required_grade_to_execute(copy._required_grade_to_execute), _target(copy._target) {}

AForm& AForm::operator=(const AForm& copy)
{
	if(this != &copy)
	{
		_is_signed = copy._is_signed;
	}
	return *this;
}

AForm::~AForm() {}



/****************************
*    overload operator		*
****************************/

std::ostream& operator<<(std::ostream& out, const AForm& AFormform)
{
	std::string signe;
	
	if (AFormform.getSignedstatus() == false)
		signe = " is not signed. ";
	else if (AFormform.getSignedstatus() == true)
		signe = " is already signed. ";
	
	out << "the AFormform : " << AFormform.getName() << signe << std::endl
		<< "The required grade to sign it is : " << AFormform.get_required_grade_to_sign() << std::endl
		<< "The required grade to execute it is : " << AFormform.get_required_grade_to_execute() << std::endl;

	return out;
}

/****************************
*   	 public methods		*
****************************/

//getter

const std::string & AForm::getName() const
{
	return _name;
}

bool AForm::getSignedstatus() const
{
	return _is_signed;
}

int AForm::get_required_grade_to_sign() const
{
	return _required_grade_to_sign;
}

int AForm::get_required_grade_to_execute() const
{
	return _required_grade_to_execute;
}

const std::string & AForm::getTarget() const
{
	return _target;
}	

// autres fonctions 

bool AForm::beSigned(const Bureaucrat & bureaucrat)	//change le status de is_signed
{
	if(bureaucrat.getGrade() > _required_grade_to_sign)
		throw GradeTooLowException();

	_is_signed = true;
	
	return true;
}

//verifie les grade et signatures pour execute
void AForm::execute(Bureaucrat const & executor) const
{
	if(executor.getGrade() > _required_grade_to_execute)		//on check si la note est assew elevee pour pouvoir executer
		throw GradeTooLowException();
	
	if (_is_signed == false)					//on check si le form a deja ete signe
		throw FormNotSignedException();

	childExecute();						//on delegue a la classe enfant pour executer le form
}


/****************************
*		 exceptions			*
****************************/


const char* AForm::GradeTooHighException::what() const throw()
{
	return "the grade to sign or execute this AFormform is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "the grade to sign or execute this AFormform is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form not already signed";
}