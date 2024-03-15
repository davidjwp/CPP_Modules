/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:50:14 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/14 23:11:20 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <iostream>
#include <exception>
#include <string>

int	main(int ac, char **av){

	if (ac == 1) {std::cerr << "Error: no arguments" << std::endl; return 1;}

	if (ac > 2) {std::cerr << "Error: too many arguments" << std::endl; return 2;}

	std::string ops(av[1]);
	try 
	{
		RPN rpn(ops);
		rpn.calculate();
	}	
	catch (std::exception& E){std::cerr << E.what() << std::endl;}
	return 0;
}