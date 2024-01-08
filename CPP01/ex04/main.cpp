/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:25:06 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/08 17:22:18 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//"<filename> <s1> <s2>"
//this is a long form string to test my program

#include "Replace.class.hpp"

int	main(int ac, char **av)
{
	if (ac != 4){
		error("missing arguments\n<filename> <s1> <s2>");
		return 1;		
	}

	if (!*av[2] || !*av[3]){
		error("bad replace arguments");
		return 2;
	}

	std::string file = (const char *)av[1];
	std::ifstream	infile(file.c_str());
	std::ofstream	outfile((file.append(".replace")).c_str());
	if (!infile.is_open() || !outfile.is_open()){
		error("file stream not open");
		if (outfile.is_open())
			std::remove(file.c_str());
		return 3;
	}

	Replace	rep(infile, outfile, av[2], av[3]);
	rep.replaceFile();
	return 0;
}