/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:26:48 by davidjwp          #+#    #+#             */
/*   Updated: 2024/03/12 23:43:49 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include "EC.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
#include <stdlib.h>

int	main(int ac, char **av){
	try {
		if (ac < 2) throw EC::FileNotGiven();
		
		std::ifstream		input_file;
	
		input_file.open(av[1]);
		if (!input_file.is_open()) throw EC::CannotOpenFile();

		Convert	conv(input_file);

		input_file.close();
	}
	catch (std::exception& E){ std::cout << "Error: " << E.what() << std::endl; return 1;}
	return 0;
}
