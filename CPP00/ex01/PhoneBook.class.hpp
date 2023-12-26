/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:24:37 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/26 19:21:32 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "main.hpp"

class PhoneBook {
public:
	PhoneBook(void);
	~PhoneBook(void);
	void	Search(void) const;

	Contact cont[8];
};

#endif