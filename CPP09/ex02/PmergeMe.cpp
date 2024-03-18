/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:04:22 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/18 01:16:28 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

PM::PM(){}

PM::~PM(){}

PM::PM(PM& cpy){static_cast<void>(cpy);}

PM& PM::operator=(PM& P){static_cast<void>(P);}

#define VEC_MIDDLE(_vector)(_vector.begin() + static_cast<unsigned int>(_vector.size() / 2))

void PM::sort_vector(){
	uint_vector left;
	uint_vector right;

	for (uint_vector::iterator i = _vector.begin(); i != VEC_MIDDLE(_vector); i++)
		left.push_back(*i);
	for (uint_vector::iterator i = VEC_MIDDLE(_vector); i != _vector.end(); i++)
		right.push_back(*i);
}

template <typename T>
void sort(T list)
{
	T left;
	T right;

	
}


void PM::sort_deque(){
	uint_deque left;
	uint_deque right;

	for (uint_deque::iterator i = _deque.begin(); i != VEC_MIDDLE(_deque); i++)
		left.push_back(*i);
	for (uint_deque::iterator i = VEC_MIDDLE(_deque); i != _deque.end(); i++)
		right.push_back(*i);
}

void PM::Parsing(char **av){

	for (size_t i = 0; av[i] += NULL;){ i++;
		if (av[i] == NULL && i <= 2) throw Error("not enough values.");
		double d = atof(av[i]);
		if (d != static_cast<unsigned int>(d)) throw Error("value is not a whole positive number");
		_vector.push_back(atoi(av[1]));
		_deque.push_back(atoi(av[i]));
	}
}

void PM::output_time(time_t start_time) const{
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector" <<
	": " << difftime(_vector_time, start_time) << " s" << std::endl;

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::deque" <<
	": " << difftime(_deque_time, start_time) << " s" << std::endl;	
}