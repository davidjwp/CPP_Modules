/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:50:14 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/13 19:02:35 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <iostream>
#include <exception>
#include <string>

//const static bool op_num(std::string op){

//	for (std::string::iterator i = op.begin(); i != op.end(); i++) {

//		if(!(*i >= 48 && *i <= 57 || (*i == 47 || *i == 45 || *i == 43 || *i == 42 || *i == 32)))
//		{std::cerr << "Error: wrong input" << std::endl; return false;}
		
//		//if (RPN::is_op(*i) && op.size() > 1) 
//		//{std::cerr << "Error: mixing operations and/or values" << std::endl; return false;}
//	}

//	if (!RPN::is_op(*op) && atoi(op) > 10) {std::cerr << "Error: value too high" << std::endl; return false;}
//	if (!RPN::is_op(*op) && atoi(op) < 0) {std::cerr << "Error: negative value" << std::endl; return false;}

//	return true;
//}

int	main(int ac, char **av){

	if (ac == 1) {std::cerr << "Error: no arguments" << std::endl; return 1;}

	if (ac > 2) {std::cerr << "Error: too many arguments" << std::endl; return 2;}

	std::string ops(av[1]);
	try 
	{
		RPN rpn(ops);
	}	
	catch (std::exception& E){std::cerr << E.what() << std::endl;}
	return 0;
}