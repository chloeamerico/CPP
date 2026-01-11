/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 13:39:43 by camerico          #+#    #+#             */
/*   Updated: 2026/01/11 17:39:17 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
	
		MutantStack();
		MutantStack(const MutantStack& copy);
		MutantStack& operator=(const MutantStack& copy);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin();
		iterator end();
};

#include "./../srcs/MutantStack.tpp"

#endif