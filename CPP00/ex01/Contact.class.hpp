/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:48:34 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/27 13:39:20 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include "main.hpp"

class Contact {
private:
	std::string	pnumb;
	std::string	dsecr;
	std::string fname;
	std::string	lname;
	std::string	nname;
public:
	int		Index;
	bool	set;

	Contact();
	Contact(int i);
	~Contact(void);
	void	add(void);
	void	getInfo(void) const;
	void	getCont(void) const;
	void	emptyContact(void);

};

#endif