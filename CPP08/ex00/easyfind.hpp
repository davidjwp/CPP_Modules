/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:30:17 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/24 21:04:42 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

class NotFound: public std::exception{
	const char* what()const throw(){ return "Element not found";}
};

#include "easyfind.tpp"

#endif