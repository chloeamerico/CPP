/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:40:41 by camerico          #+#    #+#             */
/*   Updated: 2025/12/23 16:38:47 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class AForm;

class Bureaucrat
{
	private :
	
		const std::string _name;
		int _grade;					//1 est le plus grand, 150 le plus bas

	public :

		//canonique form	

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& copy);
		~Bureaucrat();
		
		//public methods

		const std::string &getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form);
		void executeForm(AForm const & form) const;

		//exceptions

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw() ; 
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw() ; 
		};
};

//overload opertaor 

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif