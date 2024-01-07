/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:12:45 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/07 15:25:04 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal{

protected:

	std::string	type;

public:

	Animal(void);
	Animal(Animal& cpy);
	virtual ~Animal(void);

	Animal&	operator=(Animal& a1);

	virtual void	makeSound(void) const;
	std::string	getType(void) const;
};

#endif