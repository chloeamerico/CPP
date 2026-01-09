/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:48:15 by camerico          #+#    #+#             */
/*   Updated: 2026/01/09 19:36:45 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/Span.hpp"

Span::Span() : _size_max(0) {}

Span::Span(unsigned int N) : _size_max(N) {}

Span::Span(const Span& copy) : _numbers(copy._numbers), _size_max(copy._size_max) {}

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

	_numbers.push_back(nb);
}


// distance: returns the number of elements between start and end
// capacity - size: returns the number of elements that can be inserted in the container
// insert != push_back() insère exclusivement à la fin du conteneur

/* insert : permet d'insérer un élément à n'importe quelle position spécifique
	v.insert(position, valeur) ==> v.insert(v.begin() + 2, 8) insère la valeur 8 à l'index 2 */

void Span::addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	unsigned int count = std::distance(start, end);
	
	if((_numbers.size() + count) > _size_max)
		throw FullSpanException();
	
	_numbers.insert(_numbers.end(), start, end);
}


unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughNumberException();

	std::vector<int> tmp = _numbers;		//on fait une copie de _numbers
	std::sort(tmp.begin(), tmp.end());		//on trie le tmp
	
	unsigned int min_span = static_cast<unsigned int>(tmp[1] - tmp[0]);
	if (min_span == 0)
		return 0;
	for(std::size_t i = 1; i < tmp.size() - 1; i++)
	{
		unsigned int min_span_tmp = static_cast<unsigned int>(tmp[i + 1] - tmp[i]);
		
		if(min_span_tmp < min_span)
			min_span = min_span_tmp;
		if (min_span == 0)
			return 0;
	}
	return min_span;
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughNumberException();
	
	int min = _numbers[0];
	int max = _numbers[0];

	for (std::size_t i = 1; i < _numbers.size(); i++)
	{
		if (_numbers[i] < min)
			min = _numbers[i];
		if (_numbers[i] > max)
			max = _numbers[i];
	}
	return static_cast<unsigned int>(max) - static_cast<unsigned int>(min);
}

//exceptions 

const char* Span::NotEnoughNumberException::what() const throw()
{
	return "Problem detected : At least two numbers must be added to the vector to calculate the shortestSpan or longestSpan.";
}

const char* Span::FullSpanException::what() const throw()
{
	return "Problem detected : The vector has reached its maximum size (_size_max)";
}

