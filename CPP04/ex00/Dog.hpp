/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:15:28 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/06 21:38:46 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class	Dog: public Animal{

public:

	Dog(void);
	Dog(Dog& cpy);
	~Dog(void);

	Dog&	operator=(Dog& d1);
};

#endif