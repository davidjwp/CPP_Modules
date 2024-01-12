/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:37:35 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/12 17:20:51 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include <string>

class Cure: public AMateria{

private:

	std::string _type;

public:
	Cure(void);
	Cure(Cure& cpy);
	Cure(std::string const & type);
	~Cure(void);

	std::string const & getType(void) const;
	Cure*	clone(void) const; 
	virtual void use(ICharacter& target);

	virtual Cure& operator=(Cure& I1);
};

#endif