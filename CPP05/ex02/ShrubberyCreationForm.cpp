/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:18:16 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/11 22:32:46 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("default form", 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& SCF): AForm(SCF){
	*this = SCF;
}

ShrubberyCreationForm::ShrubberyCreationForm(const char *N): AForm(N, 145, 137){}

ShrubberyCreationForm::~ShrubberyCreationForm(void){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& SCF){setAttributes(SCF.getName(), SCF.getSigned());}




/*
        oooo
      ooooooooo
   ooooooooooooooo
  oooooooooooooooo
 oooo\oooooooooooooo
ooooooooooooooooooooo
  oooooooo|ooooo/oooo
    o\oo|ooooooooo
    oo\\| ooooooo
   oooo\| | //o
    ooo | |//
      \\|o|/
       \| |
     o  | |oo  oo
    ooo/  |oooooooo
*/