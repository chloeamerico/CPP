/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:59:22 by camerico          #+#    #+#             */
/*   Updated: 2025/11/17 17:54:54 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int lev_to_int(std::string str)
{
	if (str == "DEBUG")
		return 0;
	if (str == "INFO")
		return 1;
	if (str == "WARNING")
		return 2;
	if (str == "ERROR")
		return 3;
	return -1;
}


int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "Error : you should have ./HarlFilter + level" << std::endl;
		return 1;
	}
	
	Harl harl;
	
	int level = lev_to_int(argv[1]);

	switch(level) {						//switch
		case 0:
			harl.complain("DEBUG");		//utilisation du fall-through, on ne met pas de break
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
		default:
			std::cout << "Unknown level " << argv[1] << std::endl;
	}
	
	return 0;
}

