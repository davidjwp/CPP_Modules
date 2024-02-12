/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:25:12 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/12 17:36:55 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
public:

	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm&);
	RobotomyRequestForm(const char *N);
	virtual ~RobotomyRequestForm();

	const void RobotDrill(void) const;

	RobotomyRequestForm& operator=(RobotomyRequestForm&);
};


#endif