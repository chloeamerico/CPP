/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:31:09 by camerico          #+#    #+#             */
/*   Updated: 2025/11/17 16:19:39 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

//Constructeur
Harl::Harl() {}

// Destructeur
Harl::~Harl() {}


//les fonctions privees

void Harl::debug( void )
{
	// std::cout << "DEBUG" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void Harl::info( void )
{
	// std::cout << "INFO" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}
void Harl::warning( void )
{
	// std::cout << "WARNING" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error( void )
{
	// std::cout << "ERROR" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}



//fonction complain avec les pointeurs sur fonctions membres
void Harl::complain( std::string level )
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	//tableau de pointeurs sur fonctions membres
	void (Harl::*fcts[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	
	//boucle pour retrouver le bon niveau
	for (int i = 0; i < 4; i++)
	{
		if(levels[i] == level)
		{
			(this->*fcts[i])();		//on appelle la fonction correspondante
			return;
		}
	}

	std::cout << "Unknown level: " << level << std::endl;
}




//AUTRE ECRITURE PLUS COURTE (avec typedef)

// void Harl::complain(std::string level) {
//     // Typedef pour simplifier
//     typedef void (Harl::*HarlMemFn)(void);
    
//     std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
//     HarlMemFn functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    
//     for (int i = 0; i < 4; i++) {
//         if (levels[i] == level) {
//             (this->*functions[i])();
//             return;
//         }
//     }
// }