/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:20:23 by camerico          #+#    #+#             */
/*   Updated: 2025/12/22 21:02:44 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <stdexcept>
#include <iostream>
// #include <stdbool>
#include "Bureaucrat.hpp"

class Form
{
	private :
		const std::string _name;
		bool _is_signed;			//est ce que le doc est signe ou pas, non au constructeur (true = 1, false = 0)
		const int _required_grade_to_sign;
		const int _required_grade_to_execute;

	public :
		
		//canonique form

		Form();
		Form(std::string name, const int required_grade_to_sign, const int required_grade_to_execute);
		Form(const Form& copy);
		Form& operator=(const Form& copy);
		~Form();

		//public methods
		
		const std::string &getName() const;
		bool getSignedstatus() const;
		int get_required_grade_to_sign() const;
		int get_required_grade_to_execute() const;
		bool beSigned(const Bureaucrat &bureaucrat);	//change le status de is_signed

		//exceptions 

		class GradeTooHighException : public std::exception		// required_grade_to_sign et required_grade_to_execute doit etre entre 1 et 150
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

//overload operator 

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif