/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 02:20:59 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/18 00:43:10 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <ctime.h>
#include <string>

typedef std::vector<unsigned int> uint_vector;
typedef std::deque<unsigned int> uint_deque;

class PM{

private:
	uint_vector _vector;
	uint_deque _deque;

	time_t	_vector_time;
	time_t	_deque_time;

	//default constructors for coplien form
	PM();
	PM(PM&);

	PM& operator=(PM&);


public:
	
	time_t start_time;

	PM(char**);
	~PM();

	void Parsing(char**);
	void output_time(time_t) const;

	void sort_vector();
	void sort_deque();
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


#endif