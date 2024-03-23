/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:04:22 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/23 20:28:57 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include <utility>

PM::PM(){}

PM::~PM(){}

PM::PM(PM& cpy){static_cast<void>(cpy);}

PM& PM::operator=(PM& P){static_cast<void>(P);}

#define T_MIDDLE(T)(T.begin() + static_cast<unsigned int>(T.size() / 2))

const unsigned int PM::sum(pair_vector::iterator it) const{return (*it).first + (*it).second;}

//highest is a main chain
//lowest is a pend

//recursively sort pairs, first sort elements in the pairs then sort the pairs themselves 
void PM::sort_pairs(pair_vector& pairs, pair_vector::iterator curr) const{
	unsigned int swap = (*curr).first;

	if (curr != pairs.end()){
		sort_pairs(pairs, curr + 1);
		if ((*curr).second < (*curr).first) {
			(*curr).first = (*curr).second;
			(*curr).second = swap;}
		pair_vector::iterator lowest = curr;
		for (pair_vector::iterator it = curr + 1; it != pairs.end(); it++)
			if ((*it).second < (*lowest).second) lowest = it;
		pair_vector::iterator swap = curr;//check that
		curr = lowest;//and that
		lowest = swap;//that too
	}
	return ;
}


template <typename T>
bool PM::is_sorted(T list) const{
	for (T::iterator it = list.begin() + 1, T::iterator old = it - 1; it != list.end(); old = it, it++){
		if (*old > *it) return false;
		}
	return true;
}

void PM::swap(unsigned int& first, unsigned int& second) const{
	unsigned int swap = first;
	first = second;
	second = swap;
}

#define INDEX(begin, it)(begin - it)

//template <typename T, typename T_it>
//void PM::BN(T& list, )

template <typename T, typename T_it>
void PM::binary_search_sort(T& list, pair_vector& pairs, T_it last) const{
	T pend;

	for (pair_vector::iterator it = pairs.begin(); it != pairs.end(); it++)
		pend.push_back((*it).first);
	
	if (last != pairs.end()) pend.push_back(*last);

	//BN(list, );

	for (T_it mid = pend.begin() + (pend.size() / 2); pend.size();){
		T range = pend;
		for (T range = pend; range.size() > 1;){
			if (INDEX(range.begin(), mid) >= (range.size() / 2)) range = T(mid, range.end());
		}

	}
}

template <typename T, typename T_it>
T PM::sort(T& list, T_it middle){
	pair_vector pairs;
	T probes;
	
	T_it last = list.end();
	if (list.size() % 2) *(list.end() - 1) last--;

	//group pair
	for (T_it it = list.begin(); it + 1 != list.end() - 1; it++)//check for that 
		pairs.push_back(*it, *(it + 1));

	//sort pairs
	sort_pairs(pairs, pairs.begin());

	//binary search
	binary_search_sort(pairs, last);

	for (pair_vector::iterator it = pairs.begin(); it != pairs.end(); it++){
		if ((*it).first > (*it).second) probes.push_back((*it).second);
		else probes.push_back((*it).first);
	}
	
}

void PM::print() const{
	std::cout << "Before:\t";
	for (size_t i = 0; unsorted[i]; i++)
		std::cout << unsorted[i] << 32;
	std::cout << std::endl << "After:\t";
	for (size_t i = 0; _vector[i]; i++)
		std::cout << _vector[i] << 32;
	std::cout << std::endl;
}

void PM::start(){
	unsorted = _vector;
	sort(_vector, T_MIDDLE(_vector));
	_vector_time = difftime(start_time, time(NULL));
	sort(_vector, T_MIDDLE(_deque));
	_deque_time = difftime(start_time, time(NULL));}

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
	": " << _vector_time << " s" << std::endl;

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::deque" <<
	": " << _deque_time << " s" << std::endl;	
}