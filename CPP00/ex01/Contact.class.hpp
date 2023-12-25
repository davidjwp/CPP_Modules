/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidjwp <davidjwp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:48:34 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/25 22:20:30 by davidjwp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>

class Contact {
public:
	std::string fname;
	std::string	lname;
	std::string	nname;
	std::string	pnumb;
	std::string	dsecr;

	Contact(const char *na, const char *n);
	~Contact(void);
};

#endif