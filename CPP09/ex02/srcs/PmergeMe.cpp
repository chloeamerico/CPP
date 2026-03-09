/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:09:10 by camerico          #+#    #+#             */
/*   Updated: 2026/03/09 17:58:08 by camerico         ###   ########.fr       */
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
	clock_t start_vec = clock();
	ParseArg(argc, argv);
	make_pairs_vec();
	sort_high_vec();
	divide_low_pending_vec();
	insert_vec();
	clock_t end_vec = clock();
	
	// clock_t start_deq = clock();
	// clock_t end_deq = clock();
	
	print_all(start_vec, end_vec);
	
	
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

//avant d'opti
// // tri les paires en fonction du plus grand
// void PmergeMe::sort_high_vec()
// {
// 	for (size_t i = 0; i < _pairs_vec.size(); i++)
// 	{
// 		size_t index_min = i;
// 		for (size_t j = i + 1; j < _pairs_vec.size(); ++j)
// 		{
// 			if (_pairs_vec[i].second > _pairs_vec[j].second)
// 				index_min = j;
// 		}
// 		if (index_min != i)
// 			std::swap(_pairs_vec[i], _pairs_vec[index_min]);
// 	}
// }

static bool compare_pairs(const std::pair<int,int>& a, const std::pair<int,int>& b)
{
    return a.second < b.second;
}

//tri les paires en fonction du plus grand
void PmergeMe::sort_high_vec()
{
	std::sort(_pairs_vec.begin(), _pairs_vec.end(), compare_pairs);
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
		_low_vec.push_back(_pairs_vec[i].first);
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

//decider de ou placer ce nouveau nb
void PmergeMe::insert_vec()
{
	std::vector<size_t> order = insert_order_vec(_pending_vec.size());
	
	for (size_t i = 0; i < order.size(); i++)	
	{
		int index = _pending_vec[order[i]];
		std::vector<int>::iterator beg = _finalvec.begin();		//le plus bas possible
		std::vector<int>::iterator end;
		
		if (order[i] + 1 < _high_vec.size())	//ca si c'est un nb qui a un high associe
		{
			end = std::find(_finalvec.begin(), _finalvec.end(), _high_vec[order[i] + 1]);		//le high associe a ce pending
			end++;
		}
		else 
			end = _finalvec.end();

		
		while(beg < end)	//binary search entre le beg et le end
		{
			std::vector<int>::iterator mid = beg + (end - beg) / 2;
			if (index > *mid)
				beg = mid + 1;
			else
				end = mid;
		}
		
		_finalvec.insert(beg, index);
	}
}

//generer l'ordre dans lequel on va inserer les nb en se basant sur la suite de jacobsthal
std::vector<size_t> PmergeMe::insert_order_vec(size_t pending_size)
{
	std::vector<size_t> final_order; ;
	std::vector<size_t> js = jacob_suite_vec(pending_size);
	std::vector<size_t> bornes;
	
	bornes.push_back(0);		//on defini les bornes ([0], [js suite], [pending size]);
	for (size_t i = 0; i < js.size(); i++)
	{
		bornes.push_back(js[i]);
	}
	bornes.push_back(pending_size);		//ordre defini

	//on rempli entre les bornes;

	for (size_t i = 1; i < bornes.size(); i++)
	{
		size_t j = bornes[i];
		while(j > bornes[i - 1])
		{
			j--;
			if(j < pending_size)
				final_order.push_back(j);
		}
	}
	return (final_order);
}

//pour generer la suite de JS
std::vector<size_t> PmergeMe::jacob_suite_vec(size_t pending_size)
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

void PmergeMe::print_all(clock_t start_vec, clock_t end_vec)
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _finalvec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;

	std::cout << "After: ";
	for (size_t i = 0; i < _finalvec.size(); i++)
		std::cout << _finalvec[i] << " ";
	std::cout << std::endl;

	double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : "  << std::fixed << std::setprecision(5) << time_vec << " us" << std::endl;
}