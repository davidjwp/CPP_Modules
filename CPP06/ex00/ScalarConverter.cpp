/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:48:53 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/17 18:08:47 by djacobs          ###   ########.fr       */
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
	int	cast = 0;
	const char*	str = literal.c_str();
	const char* sci[6] = {"nan", "-inf", "+inf", "nanf", "-inff", "+inff"};

	char	char_cast;
	int		int_cast;
	float	float_cast;
	long	long_cast;

	if (literal[0] == '\''){
		int	len = literal.length();
		if (len != 3 && str[len - 1] != '\'')
			throw err::char_BadInput();
		else {
			char_cast = static_cast<char>(str[1]);
			int_cast = static_cast<>
			std::cout << "char: " << "\'" << static_cast<char>(str[1]) << "\'" << std::endl;
			st
		}
		cast = 1;
	}

	if (literal[0] >= 48 && literal[0] <= 57){
		int len = literal.length();
		if (str[len - 1] == 'f'){
			float_cast = static_cast<float>(std::atof(str));
			long_cast = static_cast<double>(float_cast);
			cast = 2;
		}
		else{
			long_cast = static_cast<long>(std::atof(str));
			float_cast = static_cast<long>(long_cast);
			cast = 2;
		}
		int_cast = static_cast<int>(std::atoi(str));
		if (int_cast < 0 || int_cast > 127)
			std::cout << "char: " << "impossible" << std::endl;
		else if (int_cast < 32 || int_cast == 127)
			std::cout << "char: " << "Non displayable" << std::endl;
	}
	
	for (int i = 0; i < 6; i++)
	{
		if (!literal.compare(sci[i])){
			std::cout << "char: " << "impossible\n";
			std::cout << "int: " << "impossible" << std::endl;
		}
		
	}
			

	if (!literal.compare("nan")) {float_cast = static_cast<double>(NAN); cast = 5;}
	else if (!literal.compare("-inf")) {float_cast = static_cast<double>(-INFINITY); cast = 5;}
	else if (!literal.compare("+inf")) {float_cast = static_cast<double>(INFINITY); cast = 5;}
	else if (!literal.compare("nanf")) {float_cast = static_cast<float>(NAN); cast = 5;}
	else if (!literal.compare("-inff")) {float_cast = static_cast<float>(-INFINITY); cast = 5;}
	else if (!literal.compare("+inff")) {float_cast = static_cast<float>(INFINITY); cast = 5;}

	(void)int_cast;
	switch (cast)
	{
		case 1:{
			std::cout << "int: " << static_cast<int>(char_cast);
		}
			
		case 2:{
			
		}
		case 3:{}

		case 4:{}
			
		case 5:{}

		case 0:	throw err::UnknownInput();
	}
}
