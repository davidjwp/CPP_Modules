/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:36:28 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/13 18:30:54 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"


class PresidentialPardonForm: public AForm{

public:

	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm&);
	~PresidentialPardonForm();

	PresidentialPardonForm& operator=(PresidentialPardonForm&);

	virtual void action(std::string) const;
};

#endif