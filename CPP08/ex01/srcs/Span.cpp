/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:48:15 by camerico          #+#    #+#             */
/*   Updated: 2026/01/08 21:19:28 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/Span.hpp"

Span::Span() : _size_max(0) {}

Span::Span(unsigned int N) : _size_max(N) {}

Span::Span(const Span& copy) : _size_max(copy._size_max), _numbers(copy._numbers) {}

Span& Span::operator=(const Span& copy)
{
	if (this != &copy)
	{
		_size_max = copy._size_max;
		_numbers = copy._numbers;
	}
	return *this;
}

Span::~Span() {}


//fonctions membres

void Span::addNumber(int nb)
{
	if (_numbers.size() >= _size_max)
		throw FullSpanException();
	
	else
		_numbers.push_back(nb);
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size < 2)
		throw NotEnoughNumberException();

	else 
	{
		std::vector<int> tmp = _numbers;		//on fait une copie de _numbers

		std::sort(tmp.begin(), tmp.end());		//on trie le tmp
		
		int min_span = tmp[1] - tmp[0];
		if (min_span == 0)
			return min_span;
			
		for(int i = 1; i < _size_max; i++)
		{
			int min_span_tmp = tmp[i + 1] - tmp[i];
			
			if(min_span_tmp)
		}
	}
}