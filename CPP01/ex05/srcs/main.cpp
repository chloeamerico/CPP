/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:59:22 by camerico          #+#    #+#             */
/*   Updated: 2025/11/17 16:19:25 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harl;

	std::cout << "test debug :" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	

	std::cout << "test info : " << std::endl;
	harl.complain("INFO");

	
	return 0;
}