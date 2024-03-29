/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:06:47 by davidjwp          #+#    #+#             */
/*   Updated: 2024/03/29 20:47:03 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <exception>
#include <iostream>
#include <string>

#define ARRAY "what's up doc"

int	main(void)
{
	try{
		Array<int> ok();
		(void)ok;
		Array<int> P(5, 3);
		Array<char> P2(std::string(ARRAY).length());

		for (unsigned int i = 0; i < P.size(); i++)
			std::cout << P.getElement(i);
		std::cout << std::endl;

		for (unsigned int i = 0; i < P2.size(); i++)
			P2[i] = ARRAY[i];
		
		for (unsigned int i = 0; i < P2.size(); i++)
			std::cout << P2.getElement(i);
		std::cout << std::endl;
	}
	catch (std::exception& E){
		std::cout << E.what() << std::endl;
	}
	return 0;
}