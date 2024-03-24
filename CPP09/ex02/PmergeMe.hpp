/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 02:20:59 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/24 19:03:07 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <ctime>
#include <string>

typedef std::vector<unsigned int> uint_vector;
typedef std::deque<unsigned int> uint_deque;
typedef std::vector<std::pair<unsigned int, unsigned int> > pair_vector;

class PM{

private:
	uint_vector unsorted;
	uint_vector _vector;
	uint_deque _deque;

	double	_vector_time;
	double	_deque_time;

	//default constructors for coplien form
	PM();
	PM(PM&);

	PM& operator=(PM&);


public:
	
	time_t start_time;

	PM(char**);
	~PM();

	void Parsing(char**);
	void output_time() const;
	void print() const;

	void start();
	unsigned int sum(pair_vector::iterator) const;
	void swap(unsigned int&, unsigned int&) const;
	pair_vector::iterator lowest(pair_vector::iterator, pair_vector::iterator);
	bool sorted_pairs(pair_vector&) const;
	void sort_pairs(pair_vector&, pair_vector::iterator) const;
	template <typename T>
	bool is_sorted(T, typename T::iterator) const;

	template <typename T>
	static T subrange(typename T::iterator, typename T::iterator);
	
	template <typename T>
	void binary_search_sort(T&, pair_vector&, typename T::iterator) const;

	template <typename T>
	T sort(T&, typename T::iterator);
	
	//exceptions
	class Error: public std::exception{
		std::string error;
	public:
		Error(){};
		Error(std::string msg){error = "Error: "; error + msg;}
		virtual ~Error() throw (){};
		const char* what() const throw (){return error.c_str();} 
		
	};
};

template <typename container, typename value>
static const typename container::iterator emplace(container&, typename container::iterator, value);

#endif