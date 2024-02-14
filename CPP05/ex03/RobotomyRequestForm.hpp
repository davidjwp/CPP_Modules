/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:25:12 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/14 23:08:38 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
	std::string	target;

public:

	RobotomyRequestForm();
	RobotomyRequestForm(const char*);
	RobotomyRequestForm(RobotomyRequestForm&);
	virtual ~RobotomyRequestForm();

	virtual void action(std::string) const;

	RobotomyRequestForm& operator=(RobotomyRequestForm&);
	AForm* clone(const char*);
};


#endif