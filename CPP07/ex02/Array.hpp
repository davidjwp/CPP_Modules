/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:35:04 by davidjwp          #+#    #+#             */
/*   Updated: 2024/03/29 20:24:28 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template <typename T> 
class Array{
private:
	Array();
	T* 				_ptr;
	unsigned int	_size;

public:
	Array(unsigned int);
	Array(Array<T>&);
	Array(unsigned int, int);
	~Array();
	Array<T>& operator=(Array<T>&);
	class IndexOutOfArray: public std::exception{
		const char* what()const throw(){return "Index is out of bounds";}
	};
	T& operator[](unsigned int);
	unsigned int size() const;
	T getElement(unsigned int);
};

#include "Array.tpp"

#endif