/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:16:53 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/16 19:04:22 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter{
public:
	ScalarConverter();
	ScalarConverter(ScalarConverter&);
	virtual ~ScalarConverter() = 0;

	static void convert(const std::string&);

	ScalarConverter& operator=(ScalarConverter&);
};

#endif