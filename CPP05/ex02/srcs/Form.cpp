/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:19:00 by camerico          #+#    #+#             */
/*   Updated: 2025/12/22 21:19:12 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/Form.hpp"

/****************************
*    form canonique			*
****************************/

Form::Form() : _name("Default"), _is_signed(0), _required_grade_to_sign(150), _required_grade_to_execute(150) {}

Form::Form(std::string name, const int required_grade_to_sign, const int required_grade_to_execute) : _name(name), 
	_required_grade_to_sign(required_grade_to_sign), _required_grade_to_execute(required_grade_to_execute)
{
	_is_signed = 0;

	if (required_grade_to_sign > 150 || required_grade_to_execute > 150)
		throw GradeTooLowException();
	if (required_grade_to_sign < 1 || required_grade_to_execute < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& copy) : _name(copy._name), _is_signed(copy._is_signed), 
	_required_grade_to_sign(copy._required_grade_to_sign), _required_grade_to_execute(copy._required_grade_to_execute) {}

Form& Form::operator=(const Form& copy)
{
	if(this != &copy)
	{
		_is_signed = copy._is_signed;
	}
	return *this;
}

Form::~Form() {}



/****************************
*    overload operator		*
****************************/

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	std::string signe;
	
	if (form.getSignedstatus() == false)
		signe = " is not signed. ";
	else if (form.getSignedstatus() == true)
		signe = " is already signed. ";
	
	out << "the form : " << form.getName() << signe << std::endl
		<< "The required grade to sign it is : " << form.get_required_grade_to_sign() << std::endl
		<< "The required grade to execute it is : " << form.get_required_grade_to_execute() << std::endl;

	return out;
}

/****************************
*   	 public methods		*
****************************/

const std::string & Form::getName() const
{
	return _name;
}

bool Form::getSignedstatus() const
{
	return _is_signed;
}

int Form::get_required_grade_to_sign() const
{
	return _required_grade_to_sign;
}

int Form::get_required_grade_to_execute() const
{
	return _required_grade_to_execute;
}

bool Form::beSigned(const Bureaucrat & bureaucrat)	//change le status de is_signed
{
	if(bureaucrat.getGrade() > _required_grade_to_sign)
		throw GradeTooLowException();

	_is_signed = true;
	
	return true;
}



/****************************
*		 exceptions			*
****************************/


const char* Form::GradeTooHighException::what() const throw()
{
	return "Problem detected, the grade to sign or execute this form is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Problem detected, the grade to sign or execute this form is too low";
}

