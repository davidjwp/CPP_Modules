/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:28:25 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/10 20:29:21 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria{

protected:
	std::string _type;

public:
	AMateria(void);
	AMateria(AMateria& cpy);
	AMateria(std::string const & type);
	~AMateria(void);

	std::string const & getType() const;
	
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
	
	AMateria&	operator=(AMateria& M1);
};

#endif