/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 01:36:51 by davidjwp          #+#    #+#             */
/*   Updated: 2024/03/29 20:20:35 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <exception>

template <typename T>
Array<T>::Array(void): _ptr(new T), _size(0){}

template <typename T>
Array<T>::Array(unsigned int n): _ptr(new T[n]), _size(n){}

template <typename T>
Array<T>::Array(unsigned int n, int val): _size(n){
	_ptr = new T[n];

	for (unsigned int len = 0; len < n; len++)
		_ptr[len] = static_cast<T>(val);		
}

template <typename T>
Array<T>::Array(Array& t): _size(t.size()){
	_ptr = new T[t.size()];
	for (unsigned int i = 0; i < size(); i++)
		_ptr[i] = t.getElement(i);
}

template <typename T>
Array<T>::~Array(void){delete[] _ptr;}

template <typename T>
Array<T>& Array<T>::operator=(Array<T>& A){
	for (unsigned int i = 0; i < A.size(); i++){
		if (i >= size()) throw IndexOutOfArray();
		_ptr[i] = getElement(i);
	}
	_size = A.size();
}

template <typename T>
T& Array<T>::operator[](unsigned int N){if (N >= size()) {throw IndexOutOfArray(); return _ptr[0];} return _ptr[N];}

template <typename T>
T Array<T>::getElement(unsigned int n){if (n >= size()) throw IndexOutOfArray(); return _ptr[n];}

template <typename T>
unsigned int Array<T>::size(void) const{return _size;}

