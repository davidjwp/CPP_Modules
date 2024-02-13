/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:18:16 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/13 18:39:43 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <fstream>
#include <cstdio>

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("default Shrubbery form", 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& SCF): AForm(SCF){
	*this = SCF;
}

ShrubberyCreationForm::ShrubberyCreationForm(const char *N): AForm(N, 145, 137){}

ShrubberyCreationForm::~ShrubberyCreationForm(void){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& SCF){setAttributes(SCF.getName(), SCF.getSigned()); return *this;}

void ShrubberyCreationForm::action(std::string target)const{
  std::ofstream out((target.append("_shrubbery", 11)).c_str(), std::ios_base::app);
  
  if (!out.is_open()){
    std::cerr << "shrubbery file open fail" << std::endl;
    return ;
  }

  out   <<
  "\n"  <<
  "        oooo\n" <<
  "      ooooooooo\n" <<
  "   ooooooooooooooo\n" << 
  "  oooooooooooooooo\n" <<
  " oooo\\oooooooooooooo\n" <<
  "ooooooooooooooooooooo\n" <<
  "  oooooooo|ooooo/oooo\n" <<
  "    o\\oo|ooooooooo\n" <<
  "    oo\\| ooooooo\n" <<
  "   oooo\\| | //o\n" <<
  "    ooo | |//\n" <<
  "      \\|o|/\n" <<
  "       \\| |\n" <<
  "     o  | |oo  oo\n" <<
  "    ooo/  |oooooooo\n";
}


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