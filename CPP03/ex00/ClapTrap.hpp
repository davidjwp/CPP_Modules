/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:59:18 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/05 19:38:00 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class	ClapTrap{

private:

	std::string	_Name;
	int			_Hp;
	int			_Ep;
	int			_Ad;

public:
	ClapTrap(void);
	ClapTrap(std::string n);
	ClapTrap(ClapTrap& src);
	ClapTrap(std::string n, int ad);
	~ClapTrap(void);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	int		getAd(void);
	void	setAd(int ad);
	std::string&	getName(void);
	ClapTrap&	operator=(ClapTrap& c1);
	static void	killClap(ClapTrap& v);
};


#endif