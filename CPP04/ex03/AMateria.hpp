/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:06:51 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/12 13:44:30 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "MateriaSource.hpp"
# include <string>

class AMateria: public MateriaSource{

public:
	AMateria(void);
	AMateria(AMateria& cpy);
	virtual ~AMateria(void);
	virtual void learnMateria(AMateria*) = 0;
	virtual  AMateria* createMateria(std::string const & type) = 0;

	AMateria&	operator=(AMateria& M1);
};

#endif