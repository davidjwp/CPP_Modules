/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:57:04 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/07 13:15:26 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class	WrongCat: public WrongAnimal{

public:

	WrongCat(void);
	WrongCat(WrongCat& cpy);
	~WrongCat(void);
	
	WrongCat&	operator=(WrongCat& w1);
	void	makeSound(void) const;
};

#endif