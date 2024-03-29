/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:33:52 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/24 21:05:38 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <exception>

template <typename T>
typename T::iterator easyfind(T& cont, int num){
	typename T::iterator it = cont.begin();

	while (it != cont.end() && *it != num)
		it++;
	if (it != cont.end())
		return it;
	else throw NotFound();
}