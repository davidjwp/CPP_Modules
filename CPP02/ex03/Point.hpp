/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:55:10 by davidjwp          #+#    #+#             */
/*   Updated: 2024/01/09 14:39:13 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class	Point{

private:
	const Fixed	x;
	const Fixed	y;

public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point &src);
	~Point(void);

	Point	&operator=(const Point &p1);	
	static bool	calT(const Point& a, const Point& b, const Point& c, const Point& point);
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif