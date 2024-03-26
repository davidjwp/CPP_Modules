/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:04:22 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/26 21:53:37 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <deque>
#include <vector>

PM::PM(){}

PM::~PM(){}

PM::PM(PM& cpy){static_cast<void>(cpy);}

PM& PM::operator=(PM& P){static_cast<void>(P); return P;}

#define T_MIDDLE(T)(T.begin() + static_cast<unsigned int>(T.size() / 2))

template <typename T>
void PM::assignement(T* src, T& dst){
	dst.clear();

	for (typename T::iterator it = (*src).begin(); it != (*src).end(); it++)
		dst.push_back(*it);
}

template <typename container, typename value, typename iterator>
static const iterator emplace(container& ty, iterator ty_it, value val){
	iterator end = ty.end();
	container tmp;

	ty.push_back(0);
	for (iterator it = ty.begin(); it != ty.end(); it++){
		if (tmp.size()) {*it = *tmp.begin();}
		if ((ty.begin() - it) == (ty.begin() - ty_it)){
			for (iterator tmp_it = it; it != ty.end(); tmp_it++)
				tmp.push_back(*tmp_it);
			*it = val;
		}
	}
	return end;
}

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

//it = list.begin() + 1
//template <typename T>
//bool PM::is_sorted(T list, typename T::iterator it) const{
//	for (T_it old = it - 1; it != list.end(); old = it, it++){
//		if (*old > *it) return false;
//		}
//	return true;
//}

void PM::swap(unsigned int& first, unsigned int& second) const{
	unsigned int swap = first;
	first = second;
	second = swap;
}

#define INDEX(begin, it)(begin - it)

template <typename T, typename T_it, typename T_ptr>
T_ptr PM::subrange(T_it start, T_it end, T type, T_ptr){(void)type; return new T(start, end);}

#define TO_INT(range, it)(static_cast<unsigned int>(range.begin() - it))

template <typename T>
void PM::binary_search_sort(T& list, pair_vector& pairs, typename T::iterator last) {
	T pend;
	T main_chain;

	(void)list;
	for (pair_vector::iterator it = pairs.begin(); it != pairs.end(); it++){
		pend.push_back((*it).first);
		main_chain.push_back((*it).second);
	}

	if (last != list.end()) pend.push_back(*last);

	//T *sub;
	T range;
	typename T::iterator mid;
	for (typename T::iterator range_it = range.begin(); pend.size(); pend.erase(pend.begin())){
		range = main_chain;
		mid = range.begin() + static_cast<unsigned int>(range.size() / 2);
		while(range.size() > 1){
			typename T::iterator limit = mid;
			*mid <= *pend.begin() ? limit = (range.end() - 1) : mid = range.begin();
			//TO_INT(range, mid) >= (range.size() / 2) ? limit = range.end() : limit = range.begin();			
			assignement(new T(mid, limit), range);
			mid = range.begin() + static_cast<unsigned int>(range.size() / 2);
		}
		emplace(main_chain, main_chain.begin() + TO_INT(range, mid), *mid);//give at placement the first pending
		(void)range_it;
	}
}

template <typename T>
T PM::sort(T& list, typename T::iterator middle){
	pair_vector pairs;
	T probes;
	
	(void)middle;
	typename T::iterator last = list.end();
	if (list.size() % 2) last--;

	//group pair
	for (typename T::iterator it = list.begin(); it != list.end();){
		if ((it) != last) {pairs.push_back(std::make_pair(*it, *(it + 1))); it += 2;}
		else it++;
	}

	//sort pairs
	sort_pairs(pairs, pairs.begin());

	//binary search
	binary_search_sort(list, pairs, last);

	//for (pair_vector::iterator it = pairs.begin(); it != pairs.end(); it++){
	//	if ((*it).first > (*it).second) probes.push_back((*it).second);
	//	else probes.push_back((*it).first);
	//}
	return list;
}

void PM::start(){
	unsorted = _vector;
	sort(_vector, T_MIDDLE(_vector));
	_vector_time = difftime(start_time, time(NULL));
	sort(_deque, T_MIDDLE(_deque));
	_deque_time = difftime(start_time, time(NULL));}

void PM::Parsing(char **av){

	for (size_t i = 0; av[i + 1] != NULL;){ i++;
		if (av[i] == NULL && i <= 2) throw Error("not enough values.");
		double d = atof(av[i]);
		if (d != static_cast<unsigned int>(d)) throw Error("value is not a whole positive number");
		else if (d < 0) throw Error("value is non-positive");
		_vector.push_back(atoi(av[i]));
		_deque.push_back(atoi(av[i]));
	}
}

void PM::output_time() const{
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector" <<
	": " << _vector_time << " s" << std::endl;

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::deque" <<
	": " << _deque_time << " s" << std::endl;	
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
// 2 5 1 6 3 7 4 9 8