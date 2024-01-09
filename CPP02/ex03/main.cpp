/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:37:17 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/09 15:21:15 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>

bool	Point::calT(const Point& a, const Point& b, const Point& c, const Point& p){
	const Fixed	ABC((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)));
	const Fixed PAB((p.x * (a.y - b.y) + a.x * (b.y - p.y) + b.x * (p.y - a.y)));
	const Fixed PBC((p.x * (b.y - c.y) + b.x * (c.y - p.y) + c.x * (p.y - b.y)));
	const Fixed PCA((p.x * (c.y - a.y) + c.x * (a.y - p.y) + a.x * (p.y - c.y)));

	return (PAB.toInt() + PBC.toInt() + PCA.toInt()) - ABC.toInt() < 0.0;
}

int	main( void )
{
	//const Point	a(7.24, -0.43);
	//const Point	b(-7.80, -8.47);
	//const Point	c(-1.38, -3.12);
	const Point	a(-2, -2);
	const Point	b(4.5, -3);
	const Point	c(-1, 3);
	const Point point(-2,-2.4);

	std::cout << (Point::calT(a, b, c, point) ? std::string("true") : std::string("false")) << std::endl; 
	//if (bsp(a, b, c, point))
	//	(void)0;
	return 0;
}