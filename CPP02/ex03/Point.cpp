/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:57:36 by davidjwp          #+#    #+#             */
/*   Updated: 2024/01/09 14:27:09 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void){}

Point::Point(const Point& cpy){
	*this = cpy;
}

Point::Point(const float x1, const float y1): x(x1), y(y1){}

Point::~Point(void){}

Point&	Point::operator=(const Point& p1){
	std::cout << "Assignement operator cannot assign to const type" << std::endl;
	(void)p1;
	return *this;
}

//bool	bsp(Point const a, Point const b, Point const c, Point const point){
//}