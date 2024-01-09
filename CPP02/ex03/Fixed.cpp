/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:42:01 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/09 19:50:23 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void): _raw(0){}

Fixed::~Fixed(void){}

Fixed::Fixed(const int raw){
	this->_raw = (raw * (1 << Fixed::_nbits));
}

Fixed::Fixed(const float raw){
	this->_raw = roundf(raw * (1 << Fixed::_nbits));
}

Fixed	&Fixed::operator=(const Fixed &instance){
	this->setRawBits(instance.getRawBits());
	return *this;
}

Fixed::Fixed(const Fixed &a){
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

//compare operators

bool	Fixed::operator>(const Fixed &rhs) const{
	return this->getRawBits() > rhs.getRawBits();
}

bool	Fixed::operator<(const Fixed &rhs) const{
	return this->getRawBits() < rhs.getRawBits();
}

bool	Fixed::operator>=(const Fixed &rhs) const{
	return this->getRawBits() >= rhs.getRawBits();
}

bool	Fixed::operator<=(const Fixed &rhs) const{
	return this->getRawBits() <= rhs.getRawBits();
}

bool	Fixed::operator==(const Fixed &rhs) const{
	return this->getRawBits() == rhs.getRawBits();
}

bool	Fixed::operator!=(const Fixed &rhs) const{
	return this->getRawBits() != rhs.getRawBits();
}

//operators	+ | - | * | /

Fixed	Fixed::operator+(const Fixed &rhs) const{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed &rhs) const{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed &rhs) const{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed &rhs) const{
	return Fixed(this->toFloat() / rhs.toFloat());
}

//post and pre incremental operators

Fixed	&Fixed::operator++(void){
	this->_raw += 1;
	return *this;
}

Fixed	Fixed::operator++(int){
	Fixed	tmp = *this;
	this->_raw += 1;
	return tmp;
}

Fixed	&Fixed::operator--(void){
	this->_raw -= 1;
	return *this;
}

Fixed	Fixed::operator--(int){
	Fixed	tmp = *this;
	this->_raw -= 1;
	return tmp;
}

//Min / Max

int	Fixed::min(const int i1, const int i2){
	if (i1 < i2)
		return i1;
	return i2;
}

Fixed	Fixed::min(const Fixed &f1, const Fixed &f2){
	if (f1._raw < f2._raw)
		return f1.toFloat();
	return f2.toFloat();
}

int	Fixed::max(const int i1, const int i2){
	if (i1 > i2)
		return i1;
	return i2;
}

Fixed	Fixed::max(const Fixed &f1, const Fixed &f2){
	if (f1._raw > f2._raw)
		return f1.toFloat();
	return f2.toFloat();
}
