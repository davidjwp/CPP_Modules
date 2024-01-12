/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:37:42 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/12 18:05:03 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include <string>

class MateriaSource: public IMateriaSource {

protected:
	AMateria*	_materias[4];

public:
	MateriaSource();
	MateriaSource(MateriaSource&);
	~MateriaSource();

	virtual void	learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
	bool	isFull(void) const;

	MateriaSource& operator=(MateriaSource&);
};

#endif