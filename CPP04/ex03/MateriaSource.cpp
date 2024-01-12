/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:52:37 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/12 19:56:11 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include <string>
#include "Cure.hpp"
#include "Ice.hpp"
#include <iostream>

MateriaSource::MateriaSource(void): IMateriaSource(){
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource& cpy){
	*this = cpy;
}

MateriaSource::~MateriaSource(void){
	for (int i = 0; i < 4; i++)
		delete _materias[i];
}

MateriaSource&	MateriaSource::operator=(MateriaSource& M1){
	(void)0;
	return M1;
}

void	MateriaSource::learnMateria(AMateria* materia){
	for (int i = 0; i < 4; i++){
		if (_materias[i] == NULL){
			_materias[i] = materia;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type){
	AMateria*	tmp;

	if (isFull()){
		std::cout << "no more room for materias" << std::endl;
		return NULL;
	}
	if (!type.compare("cure") || !type.compare("ice")){
		if (type.compare("cure") == 0)
			tmp = new Cure;
		else
			tmp = new Ice;
		learnMateria(tmp);
		return tmp;
	}
	std::cout << "wrong materia" << std::endl;
	return NULL;
}

bool	MateriaSource::isFull(void) const{
	for (int i = 0; i < 4; i++)
		if (_materias[i] == NULL)
			return false;
	return true;
}
