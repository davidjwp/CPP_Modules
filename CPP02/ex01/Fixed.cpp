/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:42:01 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/03 15:32:30 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void): _raw(0){
	std::cout << "Default constructor called" << std::endl;	
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int raw){
	std::cout << "Int constructor called" << std::endl;
	this->_raw = (raw * (1 << Fixed::_nbits));
}

Fixed::Fixed(const float raw){
	std::cout << "Float constructor called" << std::endl;
	this->_raw = roundf(raw * (1 << Fixed::_nbits));
}

Fixed	&Fixed::operator=(const Fixed &instance){
	std::cout << "Copy assignement operator called" << std::endl;
	this->setRawBits(instance.getRawBits());
	return *this;
}

Fixed::Fixed(const Fixed &a){
	std::cout << "Copy constructor called" << std::endl;
	*this = a;
}

int	Fixed::getRawBits(void) const{
	return this->_raw;
}

void	Fixed::setRawBits(const int raw){
	this->_raw = raw;
}

int	Fixed::toInt(void) const{
	return this->_raw >> Fixed::_nbits;
}

float	Fixed::toFloat(void) const{
	return (float)this->getRawBits() / (float)(1 << Fixed::_nbits);
}

std::ostream	&operator<<(std::ostream &o, const Fixed &rhs){
	o << rhs.toFloat();
	return o;
}