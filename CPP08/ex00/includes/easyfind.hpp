/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:31:29 by camerico          #+#    #+#             */
/*   Updated: 2026/01/11 17:58:12 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>	//pour std::find
#include <exception>

class NotFoundException : public std::exception
{
	public :
		virtual const char* what() const throw()
		{
			return "Probleme detected : ";
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int n)		//typename : pour dire que ce qui suit est un type
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);

	if(it == container.end())	//si pas trouve
		throw NotFoundException();
	
	return it;
}

#endif