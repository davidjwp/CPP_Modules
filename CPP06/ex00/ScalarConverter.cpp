/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:48:53 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/16 20:19:31 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "err.hpp"
#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

ScalarConverter::ScalarConverter(void){}

ScalarConverter::ScalarConverter(ScalarConverter& cpy){(void)cpy;}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter& S){(void)S; return *this;}

//-inf negative infinity
//+inf positive infinity 
//nan not a number

void ScalarConverter::convert(const std::string& literal){
	int	cast = 0;

	char	char_cast;
	int		int_cast;
	float	float_cast;
	long	long_cast;

	if (literal[0] == '\''){
		if (int	len = literal.length() != 3 && literal[len-1] != '\'')
			throw err::char_BadInput();
		else
			char_cast = static_cast<char>(literal[1]);
		cast = 1;
	}

	if (literal[0] >= 48 && literal[0] <= 57){
		int len = literal.length();
		if (literal[len-1] == 'f')
			float_cast = static_cast<float>
	}

	if (!literal.compare("nan")) {float_cast = static_cast<double>(NAN); cast = 5;}
	else if (!literal.compare("-inf")) {float_cast = static_cast<double>(-INFINITY); cast = 5;}
	else if (!literal.compare("+inf")) {float_cast = static_cast<double>(INFINITY); cast = 5;}
	else if (!literal.compare("nanf")) {float_cast = static_cast<float>(NAN); cast = 5;}
	else if (!literal.compare("-inff")) {float_cast = static_cast<float>(-INFINITY); cast = 5;}
	else if (!literal.compare("+inff")) {float_cast = static_cast<float>(INFINITY); cast = 5;}


	switch (cast)
	{
		case 1:
			
		case 2:

		case 3:

		case 4:
			
		case 5:
	
		case 0:	throw err::UnknownInput();
	}
}
