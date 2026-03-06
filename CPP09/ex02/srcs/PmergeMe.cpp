/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:09:10 by camerico          #+#    #+#             */
/*   Updated: 2026/03/06 18:59:49 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/PmergeMe.hpp"

//canonique form

PmergeMe::PmergeMe() : is_paire(false), pending(0) {}

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
	make_pairs_vec();
	sort_high_vec();
	divide_low_pending_vec();
	Jacob_vec();
	
	// for (size_t i = 0 ; i < _pairs_vec.size(); i++)
	// 	std::cout << "paire " << i << ": {" << _pairs_vec[i].first << ";" << _pairs_vec[i].second << "}" << std::endl;
	// if (is_paire == false)
	// 	std::cout << "pending :" << _vec.back() << std::endl;

	// std::cout << "high /final :";
	// for (size_t i = 0 ; i < _finalvec.size(); i++)
	// 	std::cout << _finalvec[i] << " ";
	// std::cout << std::endl;

	// std::cout << "low and pending : ";
	// for (size_t i = 0 ; i < _low_and_pending_vec.size(); i++)
	// 	std::cout << _low_and_pending_vec[i] << " ";
	// std::cout << std::endl;
	
}


//commune a vec et deque 

//fonction pour parser les args et l'insert dans le containeur
void PmergeMe::ParseArg(int argc, char **argv)
{
	if (argc <= 1)
		throw std::runtime_error("Error");

	for (int i = 1; i < argc; i++)
	{
		if(is_valid_num(argv[i]) == false)
			throw std::runtime_error("Error");

		int nb = std::atoi(argv[i]);
		_vec.push_back(nb);
		_deq.push_back(nb);
	}
}

//check chaque arg
bool PmergeMe::is_valid_num(const std::string &s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if(!isdigit(s[i]))
			return false;
	}

	long nb = std::atol(s.c_str());

	if (nb > INT_MAX || nb == 0)
		return false;
	return true;
}


//fonctions pour vec

//donne des paires triees a l'interieur ou le 1er <= 2eme
void PmergeMe::make_pairs_vec()
{
	for (size_t i = 0; i + 1 < _vec.size(); i += 2)
	{
		int a = _vec[i];
		int b = _vec[i + 1];
		
		if (a <= b)
			_pairs_vec.push_back(std::make_pair(a, b));
		else
			_pairs_vec.push_back(std::make_pair(b, a));
	}
	if(_vec.size() % 2 != 0)
	{
		is_paire = false;
		pending = _vec.back();		//renvoie le dernier num du container
	}
	else
		is_paire = true;
}

//tri les paires en fonction du plus grand
void PmergeMe::sort_high_vec()
{
	for (size_t i = 0; i < _pairs_vec.size(); i++)
	{
		size_t index_min = i;
		for (size_t j = i + 1; j < _pairs_vec.size(); ++j)
		{
			if (_pairs_vec[i].second > _pairs_vec[j].second)
				index_min = j;
		}
		if (index_min != i)
			std::swap(_pairs_vec[i], _pairs_vec[index_min]);
	}
}


//fonciton pour creer deux vecteurs qui vont contenir le low et le pending 
// void PmergeMe::divide_low_pending_vec()
// {
// 	for (size_t i = 0; i < _pairs_vec.size(); i++)
// 	{
// 		if (i == 0)
// 		{
// 			_finalvec.push_back(_pairs_vec[i].first);
// 			_finalvec.push_back(_pairs_vec[i].second);
// 		}
// 		else
// 		{
// 			_finalvec.push_back(_pairs_vec[i].second);
// 			_low_and_pending_vec.push_back(_pairs_vec[i].first);
// 		}
// 	} 
// 	if (is_paire == false)
// 		_low_and_pending_vec.push_back(pending);
// }

void PmergeMe::divide_low_pending_vec()
{
	for (size_t i = 0; i < _pairs_vec.size(); i++)		//on rempli avec equivalence low<==> high
	{
		_low_vec.push_back(_pairs_vec[i].first)
		_high_vec.push_back(_pairs_vec[i].second);
	}

	_finalvec.push_back(_low_vec[0]);
	
	for(size_t i = 0; i < _low_vec.size(); i++)
	{
		_finalvec.push_back(_high_vec[i]);
		
		if (i > 0)
			_pending_vec.push_back(_low_vec[i]);
	}
	if (is_paire == false)
		_pending_vec.push_back(pending);
}

//suite de Jacobsthal
void PmergeMe::insert_vec()
{
	std::vector<size_t> insert_order = instert_order(_pending_vec.size());
	
}

//generer l'ordre dans lequel on va inserer les nb en se basant sur la suite de jacobsthal
std::vector<size_t> PmergeMe::insert_order(size_t pending_size)
{
	std::vector<size_t> order
}

//pour generer la suite de JS
std::vector<size_t> PmergeMe::jacob_suite(size_t pending_size)
{
	std::vector<size_t> js;

	js.push_back(1);

	if (pending_size > 1)
		js.push_back(3);

	while (js.back() < pending_size)
	{
		size_t next;
		next = js.back() + 2 * js[js.size() - 2];		//J(n) = J(n-1) + 2 * J(n-2)  ==> dernier + 2 * avant-dernier
		js.push_back(next);
	}
	return js;
}