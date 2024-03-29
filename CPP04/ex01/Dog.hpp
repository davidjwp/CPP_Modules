/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:15:28 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/12 21:11:54 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog: public Animal{

private:
	Brain*	dogBrain;

public:

	Dog(void);
	Dog(Dog& cpy);
	Dog(const char*);
	~Dog(void);

	Dog&	operator=(Dog& d1);
	virtual void	makeSound(void) const;
	virtual void	think(void) const;
};

#endif