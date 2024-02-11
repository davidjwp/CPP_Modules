/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:03:13 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/11 22:31:33 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm{

public:

	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm& SCF);
	ShrubberyCreationForm(const char *N);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(ShrubberyCreationForm& SCF);
};

#endif