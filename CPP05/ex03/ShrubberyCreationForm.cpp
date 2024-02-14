/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:18:16 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/14 23:09:42 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <fstream>
#include <cstdio>

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("default Shrubbery target", "default Shrubbery form", 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& SCF): AForm(SCF){
	*this = SCF;
}

ShrubberyCreationForm::ShrubberyCreationForm(const char* T): AForm(T, "ShrubberyCreationForm", 145, 137){}

ShrubberyCreationForm::~ShrubberyCreationForm(void){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& SCF){setAttributes(SCF.getName(), SCF.getSigned()); return *this;}

void ShrubberyCreationForm::action(std::string Target) const{
  std::ofstream out(Target.append("_shrubbery", 11).c_str(), std::ios_base::app);
  
  if (!out.is_open()){
    std::cerr << "shrubbery file open fail" << std::endl;
    return ;
  }

  if (out.tellp())
    out.seekp(0, std::ios_base::cur);
  out   <<
  "\n"  <<
  "        oooo\t\t\t\n" <<
  "      ooooooooo\t\t\t\n" <<
  "   ooooooooooooooo\t\t\n" << 
  "  oooooooooooooooo\t\t\n" <<
  " oooo\\oooooooooooooo\t\n" <<
  "ooooooooooooooooooooo\t\n" <<
  "  oooooooo|ooooo/oooo\t\n" <<
  "    o\\oo|ooooooooo\t\t\n" <<
  "     oo\\| ooooooo\t\t\n" <<
  "   oooo\\| | //o\t\t\t\n" <<
  "    ooo | |//\t\t\t\n" <<
  "      \\\\|o|/\t\t\t\n" <<
  "       \\| |\t\t\t\t\n" <<
  "     o  | |oo  oo\t\t\n" <<
  "    ooo/  |oooooooo\t\t\n";
}

AForm* ShrubberyCreationForm::clone(const char *target){return new ShrubberyCreationForm(target);}