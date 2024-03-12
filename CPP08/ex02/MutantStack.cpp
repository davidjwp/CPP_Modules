/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidjwp <davidjwp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:08:03 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/27 17:17:55 by davidjwp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <stack>

// template <typename T>
// MutantStack<T>::MutantStack(): std::stack<T>(){}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T>& cpy){
	if (!this->empty())
		for (unsigned int i = 0; i < this->size(); i++)
			this->pop();
	for (unsigned int i = 0; i < cpy.size(); i++)
		this->push(cpy.top() - i);
}
