/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:15:48 by camerico          #+#    #+#             */
/*   Updated: 2026/02/19 13:40:12 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cerr << "Error, invalid number of arguments" << std::endl;
		return 1;
	}
	std::string input_file = argv[1];
	
	BitcoinExchange btc;
	
	btc.fill_map();
	btc.handle_input(input_file);
	
	return 0;
}