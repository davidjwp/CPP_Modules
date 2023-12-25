/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidjwp <davidjwp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:21:16 by davidjwp          #+#    #+#             */
/*   Updated: 2023/12/25 17:31:05 by davidjwp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"


Contact::Contact (const char *na, const char *n): name(na), number(n)
{
	std::cout << "contact constructed" << std::endl;
	return ;
}

Contact::~Contact (void)
{
	std::cout << "contact destroid" << std::endl;
	return ;
}
