/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:55:30 by camerico          #+#    #+#             */
/*   Updated: 2026/03/09 17:58:01 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <limits.h>
#include <utility> 		//pour std::pair et std::make_pair
#include <cstdlib>		//pour atoi et atol
#include <algorithm>
#include <ctime>
#include <iomanip>

class PmergeMe
{
	private :

		std::vector<int> _vec;
		std::deque<int>	_deq;

		std::vector<int> _low_vec;
		std::vector<int> _high_vec;
		std::vector<int> _finalvec;
		std::vector<int> _pending_vec;

		std::deque<int> _low_deq;
		std::deque<int> _high_deq;
		std::deque<int>	_finaldeq;
		std::deque<int> _pending_deq;


		std::vector<std::pair<int, int> > _pairs_vec;	//fonction pour contenir les pairs
		std::deque<std::pair<int, int> > _pairs_deq;	//fonction pour contenir les pairs

		bool is_paire;
		int pending;
		
		bool is_valid_num(const std::string &s);
		void ParseArg(int argc, char **argv);
		void print_all(clock_t start_vec, clock_t end_vec);
		
		//vec
		void make_pairs_vec();
		void sort_high_vec();
		void divide_low_pending_vec();
		void insert_vec();
		std::vector<size_t> insert_order_vec(size_t pending_size);
		std::vector<size_t> jacob_suite_vec(size_t pending_size);		

		// //deq
		// void make_pairs_deq();
		// void sort_high_deq();
		// void divide_low_pending_deq();
		// void insert_deq();
		// std::vector<size_t> insert_order(size_t pending_size);


	public :

		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& copy);;
		~PmergeMe();

		
		void run(int argc, char **argv);
};

#endif