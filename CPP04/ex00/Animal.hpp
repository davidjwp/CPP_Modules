/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidjwp <davidjwp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:12:45 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/07 00:10:09 by davidjwp         ###   ########.fr       */
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
	~Animal(void);

	Animal&	operator=(Animal& a1);

	virtual void	makeSound(void) const;
	virtual std::string	getType(void);
};

#endif