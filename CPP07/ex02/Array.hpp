/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidjwp <davidjwp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:35:04 by davidjwp          #+#    #+#             */
/*   Updated: 2024/02/21 01:42:11 by davidjwp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP


template <typename T> class Array{
private:
	T* ptr;

public:
	Array();
	Array(unsigned int);
	Array(Array&);
	~Array();

	Array& operator=(Array&);
	size_t size();
};

#endif