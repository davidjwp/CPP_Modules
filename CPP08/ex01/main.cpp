/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 23:11:08 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/25 20:41:05 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <exception>
#include <vector>
#include <iterator>

int	main()
{

	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
			
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception& E){
		std::cout << E.what() << std::endl;
	}

	try {
		std::vector<int> vc(10000);
		Span sp = Span(10000);
		
		for (unsigned int i = 0; i < 10000; i++)
			vc[i] = i;
		sp.insert(vc.begin(), vc.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception& E){
		std::cout << E.what() << std::endl;
	}

	return 0;
}
