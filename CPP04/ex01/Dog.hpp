/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:15:28 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/07 15:22:25 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog: public Animal, public Brain{

public:

	Dog(void);
	Dog(Dog& cpy);
	~Dog(void);

	Dog&	operator=(Dog& d1);
	virtual void	makeSound(void) const;
};

#endif