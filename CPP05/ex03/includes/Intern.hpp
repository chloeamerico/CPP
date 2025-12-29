/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:02:50 by camerico          #+#    #+#             */
/*   Updated: 2025/12/27 18:02:52 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

class AForm;

#include <iostream>

class Intern
{
	public :

		//canonique form

		Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& copy);
		~Intern();

		//public methods

		AForm *makeForm(const std::string form_name, const std::string target);
};

#endif