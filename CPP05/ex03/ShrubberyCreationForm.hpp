/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:03:13 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/14 23:10:11 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <string>
# include <fstream>

class ShrubberyCreationForm: public AForm{
public:

	ShrubberyCreationForm();
	ShrubberyCreationForm(const char*);
	ShrubberyCreationForm(ShrubberyCreationForm& SCF);
	virtual ~ShrubberyCreationForm();

	virtual void	action(std::string) const;
	AForm* clone(const char*);

	ShrubberyCreationForm& operator=(ShrubberyCreationForm& SCF);
};

#endif
