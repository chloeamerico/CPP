/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:40:41 by camerico          #+#    #+#             */
/*   Updated: 2025/12/19 19:38:13 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <except>

class Bureaucrat
{
	private :
	
		std::string _name const;
		int _grade;					//1 est le plus grand, 150 le plus bas

	public :

		//canonique form	

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& copy);
		~Bureaucrat();

		//overload opertaor 

		std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
		
		//public methods

		std::string getName();
		int getGrade();
		void incrementGrade();
		void decrementGrade();

		//exceptions

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw() ; 
		}
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw() ; 
		}
}