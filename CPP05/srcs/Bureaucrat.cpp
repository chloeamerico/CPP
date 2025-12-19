/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:48:59 by camerico          #+#    #+#             */
/*   Updated: 2025/12/19 19:42:01 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


/****************************
*    form canonique			*
****************************/

Bureaucrat::Bureaucrat() : _name("default"), _grade("150") {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade)

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if(this != &copy)
	{
		_name = copy._name;
		_grade = copy._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat();

/****************************
*    overload operator		*
****************************/

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat;
	return out;
}

/****************************
*   	 public methods		*
****************************/

std::string Bureaucrat::getName()
{
	return this->name;
}

int Bureaucrat::getGrade()
{
	return this->_grade;
}


/****************************
*		 exceptions			*
****************************/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Problem detected, grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Problem detected, grade too high";
}

