/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:37:35 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/10 21:16:20 by djacobs          ###   ########.fr       */
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

	Cure& operator=(Cure& I1);
};

#endif

//class AMateria{

//protected:
//	std::string _type;

//public:
//	AMateria(void);
//	AMateria(AMateria& cpy);
//	AMateria(std::string const & type);
//	~AMateria(void);

//	std::string const & getType() const;
	
//	virtual AMateria* clone() const = 0;
//	virtual void use(ICharacter& target);
	
//	AMateria&	operator=(AMateria& M1);
//};
