/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:32:19 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/10 21:21:27 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include <string>

class Ice: public AMateria{

private:

	std::string	_type;

public:

	Ice(void);
	Ice(Ice& cpy);
	Ice(std::string const & type);
	~Ice(void);

	std::string const & getType(void) const;
	
	Ice*	clone(void) const; 

	Ice& operator=(Ice& I1);

};

#endif