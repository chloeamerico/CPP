/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:09:10 by camerico          #+#    #+#             */
/*   Updated: 2026/02/25 12:14:01 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/PmergeMe.hpp"

//canonique form

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	*this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy)
{
	if(this != &copy)
	{
		_vec = copy._vec;
		_deq = copy._deq;
	}

	return *this;
}

PmergeMe::~PmergeMe() {}


/******************/

//fonction principale;
void PmergeMe::run(int argc, char **argv)
{
	ParseArg(argc, argv);
	
}

//fonction pour parser les args et l'insert dans le containeur
void PmergeMe::ParseArg(int argc, char **argv)
{
	if (argc <= 1)
		throw std::runtime_error("Error");

	for (int i = 1; i < argc; i++)
	{
		if(is_valid_num(argv[i]) == false)
			throw std::runtime_error("Error");

		int nb = std::stoi(argv[i]);
		_vec.push_back(nb);
		_deq.push_back(nb);
	}
}

//check chaque arg
bool PmergeMe::is_valid_num(std::string &s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if(!isdigit(s[i]))
			return false;
	}

	unsigned long nb = std::stoul(s);

	if (nb > INT_MAX || nb == 0)
		return false;
}