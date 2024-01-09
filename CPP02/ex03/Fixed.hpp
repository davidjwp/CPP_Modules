/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:14:14 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/09 19:11:58 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed{

private:
	int	_raw;
	static const int _nbits = 8;

public:	
	Fixed(void);
	Fixed(const int raw);
	Fixed(const float raw);
	Fixed(const Fixed &instance);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	Fixed	&operator=(const Fixed &instance);

	bool	operator>(const Fixed &instance) const;
	bool	operator<(const Fixed &instance) const;
	bool	operator>=(const Fixed &instance) const;
	bool	operator<=(const Fixed &instance) const;
	bool	operator==(const Fixed &instance) const;
	bool	operator!=(const Fixed &instance) const;

	Fixed	operator+(const Fixed &rhs) const;
	Fixed	operator-(const Fixed &rhs) const;
	Fixed	operator*(const Fixed &rhs) const;
	Fixed	operator/(const Fixed &rhs) const;
	
	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);

	static int		min(const int i1, const int i2);
	static Fixed	min(const Fixed &f1, const Fixed &f2);
	static int		max(const int i1, const int i2);
	static Fixed	max(const Fixed &f1, const Fixed &f2);
};

std::ostream &	operator<<(std::ostream &o, const Fixed &instance);

#endif