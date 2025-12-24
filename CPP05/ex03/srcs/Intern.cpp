

#include "./../includes/AForm.hpp"
#include "./../includes/Intern.hpp"
#include "./../includes/Bureaucrat.hpp"
#include "./../includes/PresidentialPardonForm.hpp"
#include "./../includes/RobotomyRequestForm.hpp"
#include "./../includes/ShrubberyCreationForm.hpp"

/****************************
*    form canonique			*
****************************/

Intern::Intern() {}

Intern::Intern(const Intern& copy)
{
	*this = copy;
}

Intern& Intern::operator=(const Intern& copy)
{
	if (this != &copy)
		*this = copy;
	return *this;
}

Intern::~Intern() {}


/****************************
*   	 public methods		*
****************************/

int form_to_int(std::string str)
{
	if (str == "shrubbery creation")
		return 0;
	if (str == "robotomy request")
		return 1;
	if (str == "presidential pardon")
		return 2;
	return -1;
}

AForm* Intern::makeForm(const std::string form_name, const std::string target)
{
	int form = form_to_int(form_name);

	switch(form) {
		case 0:
			std::cout << "Intern creates " << form_name << std::endl;
			return new ShrubberyCreationForm(target);
		case 1:
			std::cout << "Intern creates " << form_name << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "Intern creates " << form_name << std::endl;
			return new PresidentialPardonForm(target);
		default:
			std::cerr << "Problem detected : form name " << form_name << "does not exist" << std::endl;
			return NULL;
	}

}