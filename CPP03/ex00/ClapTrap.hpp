/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:59:18 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/05 13:22:49 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class	ClapTrap{

private:

	std::string	Name;
	int			Hp{10};
	int			Ep{10};
	int			Ad{0};

public:
	ClapTrap(void);
	ClapTrap(std::string &n);
	ClapTrap(ClapTrap& src);
	~ClapTrap(void);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	ClapTrap&	operator=(ClapTrap& c1);

};


#endif