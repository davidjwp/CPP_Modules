/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 19:28:19 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/22 13:46:15 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <exception>
#include <iostream>
#include <vector>
#include <ctime.h>

int	main(int ac, char **av){
	if (ac < 2) {std::cout << "Error: no arguments given." << std::endl; return 1;}

	time_t start_time;
	try
	{
		if ((time(&start_time)) == -1) throw PM::Error("time() fail.");
		
		PM Pmerge(av);
		Pmerge.Parsing(av);
		Pmerge.start();

		Pmerge.print();
		Pmerge.output_time(Pmerge.start_time);
	}
	catch (std::exception &E){ std::cout << E.what() << std::endl; return 2;}

	return 0;
}