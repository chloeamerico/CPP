/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:06:24 by camerico          #+#    #+#             */
/*   Updated: 2026/01/11 17:39:29 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//form canonique

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& copy) : std::stack<T>(copy) {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& copy)
{
	if (this != &copy)
	{
		std::stack<T>::operator=(copy);
	}
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}


//fonctions membres

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}



