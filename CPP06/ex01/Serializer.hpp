/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:44:39 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/28 21:21:23 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>

struct Data{
	int	n;
};

class Serializer{
private:
	Serializer();
	Serializer(Serializer&);

public:
	~Serializer();

	Serializer& operator=(Serializer&);
	static uintptr_t	serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};


#endif