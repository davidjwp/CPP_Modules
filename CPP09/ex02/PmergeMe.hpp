/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 02:20:59 by djacobs           #+#    #+#             */
/*   Updated: 2024/04/29 22:13:36 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <sys/time.h>

typedef std::vector<unsigned int> uint_vector;
typedef std::deque<unsigned int> uint_deque;
typedef std::vector<std::pair<unsigned int, unsigned int> > pair_vector;

class PM{

private:

	uint_vector unsorted;
	uint_vector _vector;
	uint_deque _deque;

	timeval start_time;
	timeval end_time;
	double	_vector_time;
	double	_deque_time;

	PM(PM&);
	PM& operator=(PM&);

	void sort_pairs(pair_vector&, pair_vector::iterator) const;
	template <typename T>
	void binary_search_sort(T&, pair_vector&, typename T::iterator);
	template <typename T>
	T sort(T&);	
	bool is_num(char*) const;
public:
	
	PM();
	~PM();

	void start(char**);
};

template <typename T>
static size_t to_int(T, typename T::iterator);

template <typename T, typename T_iterator>
static void assignement(T_iterator, T_iterator, T&);

template <typename container, typename value>
static void emplace(container&, unsigned int, value);

template <typename T>
static void swap(T&, T&);

class Error: public std::exception{
private:
	std::string _msg;

public:
	Error();
	virtual ~Error() throw();
	Error(const char*);
	Error(const Error&);

	Error& operator=(const Error&);
	const char* what() const throw();
};

#endif