/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:37:17 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/09 20:44:40 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>

bool	Point::bsp(const Point& a, const Point& b, const Point& c, const Point& p){
	Fixed ABC((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2);
	Fixed PAB((p.x * (a.y - b.y) + a.x * (b.y - p.y) + b.x * (p.y - a.y)) / 2); 
	Fixed PBC((p.x * (b.y - c.y) + b.x * (c.y - p.y) + c.x * (p.y - b.y)) / 2);
	Fixed PCA((p.x * (c.y - a.y) + c.x * (a.y - p.y) + a.x * (p.y - c.y)) / 2);

	return (PAB.toInt() + PBC.toInt() + PCA.toInt()) == ABC.toInt();
}

int	main( void )
{
{	const Point	a(-2, -2);
	const Point	b(4.5f, -3);
	const Point	c(-1, 3);
	const Point point(-2, -3);
	std::cout << (Point::bsp(a, b, c, point) ? std::string("true") : std::string("false")) << std::endl; 
}

{	const Point	a(-2, -2);
	const Point	b(4.5, -3);
	const Point	c(-1, 3);
	const Point point(-2, -1);
	std::cout << (Point::bsp(a, b, c, point) ? std::string("true") : std::string("false")) << std::endl; 
}
	return 0;
}