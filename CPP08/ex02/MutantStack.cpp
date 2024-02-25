/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:08:03 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/25 22:13:07 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <stack>

template <typename T>
MutantStack<T>::MutantStack(): std::stack<T>(){}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T>& cpy): Stack(cpy){}

template <typename T>
MutantStack<T>::iterator* MutantStack<T>::begin(){return this->c.begin();}

template <typename T>
MutantStack<T>::iterator* MutantStack<T>::end(){return this->c.end();}