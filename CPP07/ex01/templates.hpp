/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:58:04 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/19 00:45:27 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

#include <stddef.h>

template <typename T, typename Func> void iter(T& arr, size_t len, Func func){
	for (size_t i = 0; i < len; ++i)
		func(arr[i]);
}

#endif