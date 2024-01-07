/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:20:23 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/07 15:24:43 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain{

protected:
	
	std::string	ideas[100];

public:

	Brain(void);
	Brain(Brain& cpy);
	virtual ~Brain(void);

	Brain& operator=(Brain& b1);
};

#endif