/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:53:07 by camerico          #+#    #+#             */
/*   Updated: 2026/01/09 19:34:53 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstdlib> //pour la fonction rand()

class Span
{
	private :

		std::vector<int> _numbers;
		unsigned int	_size_max;
		Span();

	public :

		//form canonique


		Span(unsigned int N);
		Span(const Span& copy);
		Span& operator=(const Span& copy);
		~Span();

		//public methods

		void addNumber(int nb);		//ajoute une nouvelle variable au vector, faire attention a ne pas depasser N, exception sinon
		void addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		

		class NotEnoughNumberException : public std::exception		//si il y a 0 ou 1 element dans _numbers et qu'on veit trouver shortest ou longest
		{
			public:
				virtual const char* what() const throw() ; 
		};
		
		class FullSpanException : public std::exception		//si il y a deja N elements dans _numbers et qu'on veut add
		{
			public:
				virtual const char* what() const throw() ; 
		};

};

#endif