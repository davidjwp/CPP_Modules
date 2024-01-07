/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:12:45 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/07 17:53:34 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class AAnimal{

protected:

	std::string	type;

public:

	AAnimal(void);
	AAnimal(AAnimal& cpy);
	virtual ~AAnimal(void);

	AAnimal&	operator=(AAnimal& a1);

	virtual void	makeSound(void) const = 0;
	std::string	getType(void) const;
};

#endif