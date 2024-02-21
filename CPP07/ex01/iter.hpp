/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:58:04 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/21 16:14:41 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <stddef.h>

template <typename T> 

void iter(T* arr, size_t len, void(*func)(T&)){
	for (size_t i = 0; i < len; ++i)
		func(arr[i]);
}

#endif