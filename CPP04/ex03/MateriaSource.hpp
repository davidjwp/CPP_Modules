/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:37:42 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/12 13:42:45 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include <string>

class MateriaSource: public IMateriaSource {

public:
	MateriaSource();
	MateriaSource(MateriaSource&);
	~MateriaSource();

	virtual void	learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);

	MateriaSource& operator=(MateriaSource&);
};

#endif