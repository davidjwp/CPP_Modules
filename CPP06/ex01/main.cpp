/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:40:58 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/18 19:51:49 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

int	main(void)
{
	Data obj;
	uintptr_t	U1;
	Data*		U2;

	U1 = Serializer::serialize(&obj);
	U2 = Serializer::deserialize(U1);
	if (U2 == &obj)
		std::cout << "ok" << std::endl;
	else 
		std::cout << "not ok" << std::endl;
}