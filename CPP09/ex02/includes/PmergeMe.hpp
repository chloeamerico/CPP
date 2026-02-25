/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:55:30 by camerico          #+#    #+#             */
/*   Updated: 2026/02/25 12:14:40 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <limits.h>
#include <utility> 		//pour std::pair et std::make_pair


class PmergeMe
{
	private :

		std::vector<int> _vec;
		std::deque<int>	_deq;

		bool is_valid_num(std::string &s);
		void ParseArg(int argc, char **argv);

	public :

		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& copy);;
		~PmergeMe();

		
		void run(int argc, char **argv);
}

#endif