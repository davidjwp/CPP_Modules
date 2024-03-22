/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:04:22 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/22 19:46:52 by djacobs          ###   ########.fr       */
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

//pair_vector::iterator PM::lowest(pair_vector::iterator start, pair_vector::iterator end){
//	pair_vector::iterator low = start;

//	while (start != end){
//		if ((*start).first + (*start).second < (*low).first + (*low).second) low = start;
//		start++;
//	}
//	return low;
//}

const unsigned int PM::sum(pair_vector::iterator it) const{return (*it).first + (*it).second;}

//bool PM::sorted_pairs(pair_vector& pairs) const{
//	for (pair_vector::iterator it = pairs.begin(); it != pairs.end(); it++)
//		if (it + 1 != pairs.end() && sum(it) > sum(it + 1)) return false;
//	return true;
//}


//highest is a main chain
//lowest is a pend
void PM::sort_pairs(pair_vector& pairs, pair_vector::iterator iter) const{
	unsigned int swap = (*iter).first;

	if (iter != pairs.end()){
		sort_pairs(pairs, iter + 1);
		if ((*iter).second < (*iter).first) {
			(*iter).first = (*iter).second;
			(*iter).second = swap;}
	}
	return ;
}

template <typename T, typename T_it>
T PM::sort(T& list, T_it middle){
	pair_vector pairs;
	T probes;
	
	T_it pend = nullptr;
	if (list.size() % 2) *(list.end() - 1) last = list.end() - 1;

	//group pair
	for (T_it it = list.begin(); it + 1 != list.end() - 1; it++)//check for that 
		pairs.push_back(*it, *(it + 1));

	//sort pairs
	sort_pairs(pairs, pairs.begin());

	//for (pair_vector::iterator it = pairs.begin(); it != pairs.end(); it++){
	//	if ((*it).first > (*it).second)
	//		{unsigned int swap = (*it).second; (*it).second = (*it).first; (*it).first = swap;}
	//}

	rec_pairs(pairs);

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