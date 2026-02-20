/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:46:42 by camerico          #+#    #+#             */
/*   Updated: 2026/02/18 17:31:40 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>	//pour gestion des fichiers
#include <cstdlib>
#include <cctype>

class BitcoinExchange
{
	private :
		
		std::map<std::string, float>	_data_base;	//stock la base de donnees en (date->prix)

	public :

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& copy);
		~BitcoinExchange();

		int fill_map();
		void handle_input(std::string input_file);
		void calcul(std::string date, std::string quant);
		
};

#endif