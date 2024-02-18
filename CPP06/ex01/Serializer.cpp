/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:44:39 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/18 21:35:02 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <stdint.h>

Serializer::Serializer(){}

Serializer::Serializer(Serializer& S){(void)S;}

Serializer::~Serializer(){}

Serializer& Serializer::operator=(Serializer& S){(void)S; return *this;}

uintptr_t	Serializer::serialize(Data* ptr){return reinterpret_cast<uintptr_t>(ptr);}

Data*	Serializer::deserialize(uintptr_t raw){return reinterpret_cast<Data*>(raw);}