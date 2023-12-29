/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:38:37 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/29 21:40:10 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.class.hpp"

Replace::Replace(void){}

Replace::~Replace(void){}

Replace::Replace(std::ifstream &infile, std::ofstream &outfile, std::string s1, std::string s2)
: in(&infile), out(&outfile), s1(s1), s2(s2){}

void	Replace::replaceFile(void){//this is unfinished
	std::string	cont;

	while (std::getline(*(this->in), cont)){
		if (!this->in->eof())
			cont += '\n';
		while (cont.find(this->s1) != -1){
			
		}
			
		*(this->out) << cont;
	}
}

void	error(std::string msg){
	std::cerr << RED << "Error: " << RES << msg << std::endl;
}
