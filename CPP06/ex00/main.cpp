/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:23:34 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/16 19:22:12 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>
#include "ScalarConverter.hpp"

int	main(int ac, char** av)
{
	if (ac > 1)
		try { ScalarConverter::convert(std::string(av[1])); }
		catch(const std::exception& e){ std::cerr << "Error: " << e.what() << '\n'; }
	return 0;
}