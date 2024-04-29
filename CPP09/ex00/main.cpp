/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:26:48 by davidjwp          #+#    #+#             */
/*   Updated: 2024/04/29 20:56:05 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
#include <stdlib.h>

int	main(int ac, char **av){
	try {
		if (ac < 2) throw Error("Missing file");
		
		std::ifstream		input_file;
	
		input_file.open(av[1]);
		if (!input_file.is_open()) throw Error("could not open file");

		BitcoinExchange	conv(input_file);

		input_file.close();
	}
	catch (std::exception& E){ std::cerr << "Error: " << E.what() << std::endl; return 1;}
	return 0;
}
