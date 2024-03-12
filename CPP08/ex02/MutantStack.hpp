/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidjwp <davidjwp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:55:50 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/27 21:40:19 by davidjwp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack: public std::stack<T, typename std::deque<T> >{
public:
	MutantStack(){};
	MutantStack(MutantStack<T>&);
	~MutantStack(){};

	//this defines the iterator for MS to be the deque iterator derived in the stack class
	typedef typename MutantStack<T>::container_type::iterator iterator;
	
	MutantStack<T>& operator=(MutantStack<T>& M){
		if (M.empty())
			this->c.clear();
		this->c = M.c;
	}

	iterator begin(){return this->c.begin();}
	iterator end(){return this->c.end();}
};

#endif