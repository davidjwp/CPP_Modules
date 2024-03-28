/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:04:22 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/28 18:48:07 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <exception>
#include <cstdlib>
#include <utility>
#include <deque>
#include <vector>
#include <sys/time.h>

PM::PM(){}

PM::~PM(){}

PM::PM(PM& cpy){static_cast<void>(cpy);}

PM& PM::operator=(PM& P){static_cast<void>(P); return P;}

double getElapsedTime(timeval start, timeval end){
	long seconds = end.tv_sec - start.tv_sec;
	long microseconds = end.tv_usec - start.tv_usec;
	return seconds + microseconds*1e-6;
}

//convert an iterator to it's position in the container
template <typename T>
static size_t to_int(T type, typename T::iterator it) {
		size_t i = 0;

	for (typename T::iterator ty = type.begin(); *ty != *it; ty++)
		i++;
	return i;
}

//assign a ranged container to another container
template <typename T, typename T_iterator>
static void assignement(T_iterator start, T_iterator end, T& dst){
	T src = T(start, end);
	dst.clear();

	for (typename T::iterator it = src.begin(); it != src.end(); it++)
		dst.push_back(*it);
}

//works like the emplace container member function in c++11 
template <typename container, typename value>
static void emplace(container& ty, unsigned int ty_i, value val){
	container tmp;

	for (typename container::iterator it = ty.begin(); it != ty.end(); it++){
		if (to_int(ty, it) == ty_i){
			tmp.push_back(val);
			for (typename container::iterator tmp_it = it; tmp_it != ty.end(); tmp_it++) {
				tmp.push_back(*tmp_it);
				if (it != ty.end() - 1) it++;
				}
		}
		else tmp.push_back(*it);
	}
	ty.clear();
	assignement(tmp.begin(), tmp.end(), ty);
}

//recursively sort pairs, first sort elements in the pairs then sort the pairs themselves 
void PM::sort_pairs(pair_vector& pairs, pair_vector::iterator curr) const{
	if (curr != pairs.end()){
		sort_pairs(pairs, curr + 1);
		if ((*curr).second < (*curr).first) {
			unsigned int swap = (*curr).first;
			(*curr).first = (*curr).second;
			(*curr).second = swap;}
		pair_vector::iterator lowest = curr;
		for (pair_vector::iterator it = curr + 1; it != pairs.end(); it++)
			if ((*it).second < (*lowest).second) lowest = it;
		pair_vector::iterator swap = curr;
		curr = lowest;
		lowest = swap;
	}
	return ;
}

template <typename T>
void PM::binary_search_sort(T& list, pair_vector& pairs, typename T::iterator last) {
	T pend;
	T main_chain;

	for (pair_vector::iterator it = pairs.begin(); it != pairs.end(); it++){
		pend.push_back((*it).first);
		main_chain.push_back((*it).second);
	}

	if (last != list.end()) pend.push_back(*last);

	T range;
	for (typename T::iterator mid; pend.size(); pend.erase(pend.begin())){
		range = main_chain;
		mid = range.begin() + static_cast<unsigned int>(range.size() / 2);
		while(range.size() > 2){
			typename T::iterator limit = mid + 1;
			*mid <= *pend.begin() ? limit = range.end() : mid = range.begin();
			assignement(mid, limit, range);
			mid = range.begin() + static_cast<unsigned int>(range.size() / 2);
		}
		*range.begin() > *pend.begin() ? mid = range.begin() : mid = range.end() - 1;
		emplace(main_chain, to_int(main_chain, mid), *pend.begin());
	}
	assignement(main_chain.begin(), main_chain.end(), list);
}

template <typename T>
T PM::sort(T& list){
	pair_vector pairs;
	
	typename T::iterator last = list.end();
	if (list.size() % 2) last--;

	//turn the container into pairs
	for (typename T::iterator it = list.begin(); it != list.end();){
		if ((it) != last) {pairs.push_back(std::make_pair(*it, *(it + 1))); it += 2;}
		else it++;
	}

	sort_pairs(pairs, pairs.begin());
	binary_search_sort(list, pairs, last);
	return list;
}

bool PM::is_num(char* av) const{
	for (unsigned int i = 0; av[i]; i++)
		if (!((av[i] == 46 || av[i] == 45) || (av[i] >= 48 && av[i] <= 57))) return false;
	return true;
}

void PM::start(char**av){
	if (gettimeofday(&start_time, NULL) == -1) throw PM::Error("gettimeofday() fail.");

	//Parsing
	for (size_t i = 0; av[i + 1] != NULL;){ i++;
		if (!is_num(av[i])) throw Error("bad symbols.");
		if (av[i] == NULL && i <= 2) throw Error("not enough values.");
		double d = atof(av[i]);
		if (d != static_cast<unsigned int>(d)) throw Error("value is not a whole positive number");
		else if (d < 0) throw Error("value is non-positive");
		_vector.push_back(atoi(av[i]));
		_deque.push_back(atoi(av[i]));
	}

	unsorted = _vector;
	sort(_vector);
	if (gettimeofday(&end_time, NULL) == -1) throw PM::Error("gettimeofday() fail.");
	_vector_time = getElapsedTime(start_time, end_time);
	sort(_deque);
	if (gettimeofday(&end_time, NULL) == -1) throw PM::Error("gettimeofday() fail.");
	_deque_time = getElapsedTime(start_time, end_time);

	//Print
	std::cout << "Before:\t";
	for (uint_vector::iterator i = unsorted.begin(); i != unsorted.end(); i++)
		std::cout << *i << ' ';
	std::cout << std::endl << "After:\t";
	for (uint_vector::iterator i = _vector.begin(); i != _vector.end(); i++)
		std::cout << *i << ' ';
	std::cout << std::endl;

	//Print time
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector" <<
	": " << _vector_time << " seconds" << std::endl;

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::deque" <<
	": " << _deque_time << " seconds" << std::endl;	
}

// 2 5 1 6 3 7 4 9 8