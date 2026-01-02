/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:43:26 by camerico          #+#    #+#             */
/*   Updated: 2026/01/02 20:38:22 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #pragma once

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T& a, T& b)
{
	T tmp;
	
	tmp = a;
	a = b;
	b = tmp;
	
}

template <typename T>
T min(T a, T b)
{
	if (a < b)
		return a;
	else
		return b;
}

template <typename T>
T max(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}

#endif