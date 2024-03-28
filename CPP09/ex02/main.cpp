/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 19:28:19 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/28 17:46:37 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <exception>
#include <iostream>
#include <vector>
#include <ctime>
#include <sys/time.h>

int	main(int ac, char **av){
	if (ac < 2) {std::cout << "Error: no arguments given." << std::endl; return 1;}

	try
	{
		PM Pmerge;
		Pmerge.start(av);
	}
	catch (std::exception &E){ std::cout << E.what() << std::endl; return 2;}

	return 0;
}