/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidjwp <davidjwp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:50:56 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/20 18:32:22 by davidjwp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP


template <typename T> void swap(T& a, T& b){
	T tmp = b;
	b = a;
	a = tmp;
}

template <typename T> T min(T a, T b){
	if (a < b)
		return a;
	return b;
}

template <typename T> T max(T a, T b){
	if (a > b)
		return a;
	return b;
}

#endif