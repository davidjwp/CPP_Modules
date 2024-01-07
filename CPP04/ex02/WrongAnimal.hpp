/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:04:14 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/07 13:07:36 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class	WrongAnimal{

protected:

	std::string	type;

public:

	WrongAnimal(void);
	WrongAnimal(WrongAnimal& cpy);
	~WrongAnimal(void);

	WrongAnimal&	operator=(WrongAnimal& W1);
	std::string	getType(void) const;
	void	makeSound(void)const;
};

#endif