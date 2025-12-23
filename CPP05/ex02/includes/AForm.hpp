/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:20:23 by camerico          #+#    #+#             */
/*   Updated: 2025/12/23 13:52:37 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <stdexcept>
#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	private :
		const std::string _name;
		bool _is_signed;			//est ce que le doc est signe ou pas, non au constructeur (true = 1, false = 0)
		const int _required_grade_to_sign;
		const int _required_grade_to_execute;
		std::string _target;

	public :
		
		//canonique form

		AForm();
		AForm(std::string name, std::string target, const int required_grade_to_sign, const int required_grade_to_execute);
		AForm(const AForm& copy);
		AForm& operator=(const AForm& copy);
		virtual ~AForm();

		//public methods
		
		const std::string &getName() const;
		bool getSignedstatus() const;
		int get_required_grade_to_sign() const;
		int get_required_grade_to_execute() const;
		const std::string &getTarget() const;					//nouveau ex02
		bool beSigned(const Bureaucrat &bureaucrat);	//change le status de is_signed
		void execute(Bureaucrat const & executor) const;		//nouveau ex02, pour check les grade et signatures
		virtual void childExecute() const = 0; 

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
		
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw() ;
		};

};

//overload operator 

std::ostream& operator<<(std::ostream& out, const AForm& Aform);

#endif