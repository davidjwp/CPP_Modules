/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidjwp <davidjwp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:15:28 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/07 00:11:24 by davidjwp         ###   ########.fr       */
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
	void	makeSound(void) const override;
	std::string	getType(void) override;
};

#endif