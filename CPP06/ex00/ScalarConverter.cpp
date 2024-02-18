/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:48:53 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/18 18:35:24 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "err.hpp"
#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

ScalarConverter::ScalarConverter(void){}

ScalarConverter::ScalarConverter(ScalarConverter& cpy){(void)cpy;}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter& S){(void)S; return *this;}

void ScalarConverter::convert(const std::string& literal){
	std::string sci[6] = {"nan", "-inf", "+inf", "nanf", "-inff", "+inff"};

	int		int_cast;
	float	float_cast;

	if (literal.size() == 1 && std::isalpha(literal[0]) && std::isprint(literal[0])){
		std::cout << "char: " << "\'" << static_cast<char>(literal[0]) << "\'" << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[0]) << std::endl;
		std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;
		return ;
	}

	float_cast = std::atof(literal.c_str());
	int_cast = std::atoi(literal.c_str());

	for (int i = 0; i < 6; i++)
		if (!literal.compare(sci[i])){
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			if (i <= 2)
				std::cout << "float: " << sci[i] << 'f' << std::endl;
			else 
				std::cout << "float: " << sci[i] << std::endl;
			std::cout << "double: " << sci[i] << std::endl;
			return ;		
		}

	if ((int_cast > 127 || int_cast < 0) && !std::isprint(int_cast))
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(int_cast))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "\'" << static_cast<char>(int_cast) << "\'" << std::endl;

	std::cout << "int: " <<  static_cast<int>(int_cast) << std::endl;
	if (std::fmod(float_cast, 1.0) == 0.0)
		std::cout << "float: " << static_cast<float>(float_cast) << ".0" << "f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(float_cast) << "f" << std::endl;
	if (std::fmod(float_cast, 1.0) == 0.0)
		std::cout << "double: " << static_cast<float>(float_cast) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<float>(float_cast) << std::endl;
}
