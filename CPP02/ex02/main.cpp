/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:37:17 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/03 17:32:28 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;


	std::cout << a + b << std::endl;
	std::cout << a + 2 << std::endl;
	std::cout << a + b << std::endl;
	std::cout << a + b << std::endl;
	std::cout << a + b << std::endl;
	std::cout << a + b << std::endl;
	std::cout << a + b << std::endl;
	return 0;
}