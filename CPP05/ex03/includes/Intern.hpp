
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