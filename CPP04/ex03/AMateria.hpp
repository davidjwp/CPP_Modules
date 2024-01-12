/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:06:51 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/12 17:21:13 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class ICharacter;

class AMateria{

protected:
	std::string	_type;

public:
	AMateria(void);
	AMateria(AMateria& cpy);
	AMateria(std::string const & type);
	virtual ~AMateria(void);

	virtual std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void	use(ICharacter& target);

	AMateria&	operator=(AMateria& M1);
};

#endif