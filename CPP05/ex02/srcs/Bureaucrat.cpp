/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:48:59 by camerico          #+#    #+#             */
/*   Updated: 2025/12/23 18:16:48 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/Bureaucrat.hpp"
#include "./../includes/AForm.hpp"

/****************************
*    form canonique			*
****************************/

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if(this != &copy)
	{
		// _name = copy._name;		ne peut pas reassigner _name car il est const
		_grade = copy._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

/****************************
*    overload operator		*
****************************/

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade : " << bureaucrat.getGrade();
	return out;
}

/****************************
*   	 public methods		*
****************************/

const std::string &Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;	//si aucune exception n'est lancee, tout s'est bien passe
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because is grade is too low." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " execute " << form.getName() << std::endl;	//si aucune exception n'est lancee, tout s'est bien passe
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << "can't execute form : " << form.getName() << " because " << e.what() << std::endl;
	}
	
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
	return "Problem detected, grade too low";
}

