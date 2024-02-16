/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:48:53 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/16 20:05:12 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (int	len = literal.length() != 3 && literal[len] != '\'')
			throw err::char_BadInput();
		else
			char_cast = static_cast<char>(literal[1]);
		cast = 1;
	}

	if (literal[0] >= 48 && literal[0] <= 57){
				
	}
	
	switch (cast)
	{
		case 1:
		
		case 2:

		case 3:

		case 4:

		case 0:
	}
}
