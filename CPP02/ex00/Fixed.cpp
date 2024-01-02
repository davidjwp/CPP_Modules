/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:42:01 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/02 18:22:07 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void): _raw(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
	return this->_raw;
}

void	Fixed::setRawBits(const int raw){
	this->_raw = raw;
}
