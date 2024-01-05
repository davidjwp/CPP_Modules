/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidjwp <davidjwp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:55:10 by davidjwp          #+#    #+#             */
/*   Updated: 2024/01/05 12:05:19 by davidjwp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class	Point{

private:
	Fixed	x;
	Fixed	y;

public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point &src);
	~Point(void);

	Point	&operator=(const Point &p1);
};

#endif