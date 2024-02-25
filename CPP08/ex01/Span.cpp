/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 21:12:17 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/25 20:42:54 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iterator>
#include <vector>
#include <algorithm>
#include <exception>
#include <iostream>

Span::Span(void): _curr(0), _size(0), _vec(std::vector<int>()){}

Span::Span(unsigned int size): _curr(0), _size(size), _vec(std::vector<int>(size)){}

Span::Span(const Span& cpy): _curr(0), _size(cpy.getSize()){_vec = cpy.getVec(); _curr = cpy.getCurr();}

void Span::insert(IT start, IT end){
	if (std::distance(start, end) < _size)
		throw SpanSizeReached();
	_vec.insert(_vec.end(), start, end);
}

Span::~Span(){}

Span& Span::operator=(Span& S){
	for (unsigned int i = 0; i < this->getSize(); i++)
		_vec.at(i) = S.getVec().at(i);
	_curr = S.getCurr();
	return *this;
}

void Span::addNumber(int num){
	if (_curr <= _size)
		_vec.at(_curr++) = num;
	else
		throw SpanSizeReached();
}

unsigned int Span::shortestSpan(){
	IT it = _vec.begin();

	int small1 = *std::min_element(_vec.begin(), _vec.end());	
	int	small2 = *std::max_element(_vec.begin(), _vec.end());
	while (it != _vec.end()){
		if (*it < small2 && *it != small1)
			small2 = *it;
		it++;
	}
	return static_cast<unsigned int>(small2 - small1) - 1;
}

unsigned int Span::longestSpan() const{ 
	int	max = *std::max_element(_vec.begin(), _vec.end());
	int min = *std::min_element(_vec.begin(), _vec.end());
	
	return static_cast<unsigned int>(max - min);
}

unsigned int Span::getSize() const{return _size;}

unsigned int Span::getCurr() const{return _curr;}

std::vector<int> Span::getVec() const{return _vec;}
