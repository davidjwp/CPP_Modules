/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:03:13 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/14 18:21:21 by djacobs          ###   ########.fr       */
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

	ShrubberyCreationForm& operator=(ShrubberyCreationForm& SCF);
};

#endif
