/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:16:53 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/28 21:15:16 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter&);

public:
	virtual ~ScalarConverter() = 0;

	static void convert(const std::string&);

	ScalarConverter& operator=(ScalarConverter&);
};

#endif