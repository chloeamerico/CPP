/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:30:44 by camerico          #+#    #+#             */
/*   Updated: 2026/01/05 14:22:25 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/Array.hpp"

/*ex pour allouer un tableau de int :
	- int* arr = new[5];
	- delete [] arr;
*/


/****************************
*    form canonique			*
****************************/


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

		if (_sizeTab == 0)
			_arr = NULL;
		else 
		{
			_arr = new T[_sizeTab];
			for (unsigned int i = 0; i < _sizeTab; i++)
				_arr[i] = copy._arr[i];
		}
	}

	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _arr;
}


/****************************
*    overload operator		*
****************************/

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _sizeTab)
		throw IndexTooHighException();
	
	return _arr[index];
}

//pour pouvoir gerer un tab const
template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _sizeTab)
		throw IndexTooHighException();
	
	return _arr[index];
}

/****************************
*		 exceptions			*
****************************/

template <typename T>
const char* Array<T>::IndexTooHighException::what() const throw()
{
	return "Probem detected, Index too high";
}

/****************************
*   	 public methods		*
****************************/

template <typename T>
unsigned int Array<T>::size() const
{
	return _sizeTab;
}