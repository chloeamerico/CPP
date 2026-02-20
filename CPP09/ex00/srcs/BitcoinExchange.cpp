
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 20:02:52 by camerico          #+#    #+#             */
/*   Updated: 2026/02/17 16:28:51 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/BitcoinExchange.hpp"

//forme canonique

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) : _data_base(copy._data_base) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if (this != &copy)
		_data_base = copy._data_base;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

/****************************
* 		static methods		*
****************************/


static bool valid_format(std::string date)
{
	if (date.length() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;

	for (int i = 0; i <= 3; i++)
	{
		if(!isdigit(date[i]))
			return false;
	}
	for (int i = 5; i <= 6; i++)
	{
		if(!isdigit(date[i]))
			return false;
	}
	for (int i = 8; i <= 9; i++)
	{
		if(!isdigit(date[i]))
			return false;
	}
	return true;
}

//annee bissextile si divisible 4 ET
// non divisible par 100 ou divisible par 400
static bool anneebis(int year)
{
	if(year % 4 != 0)
		return false;
	if(year % 100 != 0)
		return true;
	if (year % 400 == 0)
		return true;
	return false;
}

static bool is_valid_date(std::string date)
{
	if(valid_format(date) == false)
		return false;

	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;

	int tab_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	//annees bissextiles
	if(month == 2 && anneebis(year) == true)
		tab_months[1] = 29;
	
	if(day < 1 || day > tab_months[month - 1])
		return false;

	return true;
}


//Check du nb de bitcoin
static bool is_valid_quantite(std::string quantite)
{
	if(quantite.empty())
		return false;
	
	bool has_decimal = false;

	for (size_t i = 0; i < quantite.length(); i++)
	{
		if(isdigit(quantite[i]))
			continue;
		
		else if (quantite[i] == '.' && has_decimal == false)
		{
			has_decimal = true;

			if (i == 0 || i == quantite.length() - 1)
			{
				std::cerr << "Error: bad input" << std::endl;
				return false;
			}
		}
		else if ( quantite[0] != '-')
		{
			std::cerr << "Error: invalid char : " << quantite[i] << std::endl;
			return false;
		}
		
	}

	float nb = atof(quantite.c_str());

	if(nb < 0)
	{
		std::cerr << "Error: not a positive number" << std::endl;
		return false;
	}

	if(nb > 1000)
	{
		std::cerr << "Error: too large a number" << std::endl;
		return false;
	}
	return true;
}

static void delete_spaces(std::string& str)
{
	size_t start = 0;
	size_t end = str.size();

	//premier char qui n'est pas un espace
	while(start < end && str[start] == ' ')
		start++;

	//dernier char qui n'est pas un espace
	while(end > start && str[end - 1] == ' ')
		end--;

	str = str.substr(start, end - start);
}

/****************************
* 	gestion de data.csv		*
****************************/

//fonction poru ouvrir le fichier data.csv, le lire et remplir la map avec key->value
int BitcoinExchange::fill_map()
{
	std::string file_name = "data.csv";
	std::ifstream infile(file_name.c_str());	//on ouvre le fichier en mode lecture

	if(!infile.is_open())
	{
		std::cerr << "Error openning file " << file_name << std::endl;
		return 1;
	}
	
	//on lit ligne par ligne pour remplir la map

	std::string line;
	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		size_t virgule = line.find(',');	//on cherche la virgule

		if (virgule != std::string::npos)
		{
			std::string date = line.substr(0, virgule);		//on recup la date
			std::string value = line.substr(virgule + 1);
			
			float val = atof(value.c_str());

			_data_base[date] = val;		//on ajoute a la map
		}
	}
	infile.close();
	return 0;
}


/****************************
* 	gestion de input.txt	*
****************************/

void BitcoinExchange::handle_input(std::string input_file)
{
	std::ifstream infile(input_file.c_str());
	
	if(!infile.is_open())
	{
		std::cerr << "Error openning file " << input_file << std::endl;
		return;
	}
	
	std::string line;
	std::getline(infile, line);		//on skip la premiere ligne
	
	while (std::getline(infile, line))
	{
		size_t pipe = line.find('|');	//on cherche le pipe
		
		if (pipe != std::string::npos)
		{
			//DATE
			std::string date = line.substr(0, pipe);
			delete_spaces(date);			//on supp les espaces

			if(is_valid_date(date) == false)			//on check si c'est valide
			{
				std::cerr << "Error: bad input => " << date << std::endl;
				continue;
			}

			//QUANTITE
			std::string quantite = line.substr(pipe + 1);
			delete_spaces(quantite);

			if(is_valid_quantite(quantite) == false)
				continue;
			
			calcul(date, quantite);
		}
		else
			std::cerr << "Error: bad input => " << line << std::endl;
	}
	infile.close();
}







/****************************
* 			calcul			*
****************************/

void BitcoinExchange::calcul(std::string date, std::string quant)
{
	float quantite = atof(quant.c_str());
	float multiplication;

	std::map<std::string, float>::iterator it = _data_base.find(date); 

	if (it != _data_base.end())		//si on a trouve la date exacte
	{
		multiplication = quantite * it->second;
		std::cout << date << " => " << quantite << " = " << multiplication << std::endl;
		return;
	}

	//si pas la date exacte :
	else 
	{
		it = _data_base.upper_bound(date);		//upper_bound pour trouver la date qui se rapproche le plus

		if (it == _data_base.begin())	//date < a la premiere date dans la DB
		{
			std::cerr << "Error : date too early => " << date << std::endl;
			return;
		} 

		else
		{
			--it;
			multiplication = quantite * it->second;
			std::cout << date << " => " << quantite << " = " << multiplication << std::endl;
			return;
		}
	}

}
