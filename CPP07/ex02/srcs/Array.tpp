/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:30:44 by camerico          #+#    #+#             */
/*   Updated: 2026/01/03 19:26:05 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/Array.hpp"

/*ex pour allouer un tableau de int :
	- int* arr = new[5];
	- delete [] arr;
*/

//creer un tableau vide
template<typename T>
Array<T>::Array() : _arr(NULL), _sizeTab(0) {}

//creer un tab de n elements
template<typename T>
Array<T>::Array(unsigned int n) : _sizeTab(n)
{
	if (_sizeTab == 0)			//cas ou _size == 0
		_arr = NULL;
	
	else 
		_arr = new T[n];
}

template<typename T>
Array<T>::Array(const Array& copy) : _sizeTab(copy._sizeTab)
{
	if (_sizeTab == 0)			//cas ou _size == 0
		_arr = NULL;
	
	else 
	{	
		_arr = new T[_sizeTab];		//on alloue un noubeau tab

		for(unsigned int i = 0; i < _sizeTab; i++)		//on copie chaque ligne dans le nouveau tab
			this->_arr[i] = copy._arr[i];

	}

	

}

template<typename T>
Array<T>&	Array<T>::operator=(const Array& copy)
{

	if(this != &copy)
	{
		_sizeTab = copy._sizeTab;
		
		delete[] _arr;
		_arr = new T[_sizeTab];
		for (unsigned int i = 0; i < _sizeTab; i++)
			_arr[i] = copy._arr[i];
	}

	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _arr;
}


