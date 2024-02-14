/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:36:28 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/14 23:06:24 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"


class PresidentialPardonForm: public AForm{
private:
	std::string	target;

public:

	PresidentialPardonForm();
	PresidentialPardonForm(const char*);
	PresidentialPardonForm(PresidentialPardonForm&);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm& operator=(PresidentialPardonForm&);

	virtual void action(std::string) const;
	AForm* clone(const char*);
};

#endif