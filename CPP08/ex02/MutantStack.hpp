/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:55:50 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/25 22:12:32 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack: public std::stack<T>{

public:
	MutantStack();
	MutantStack(MutantStack&);
	~MutantStack();

	MutantStack& operator=(MutantStack&);
	
	class iterator: public MutantStack<T>{};
	MutantStack::iterator* begin();
	MutantStack::iterator* end();
	
	void operator++(MutantStack::iterator*) const;//change these for pre and post
	void operator--(MutantStack::iterator*) const;
};

#endif