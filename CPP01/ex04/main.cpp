/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:25:06 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/29 21:11:31 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//"<filename> <s1> <s2>"

#include "Replace.class.hpp"

int	main(int ac, char **av)
{
	if (ac != 4){
		error("missing arguments\n<filename> <s1> <s2>");
		return 0;		
	}

	std::string file = (const char *)av[1];
	std::ifstream	infile(file.c_str());
	std::ofstream	outfile(file + ".replace");
	if (!infile.is_open() || !outfile.is_open()){
		error("file stream not open");
		return 0;
	}

	Replace	rep(infile, outfile, av[2], av[3]);
	rep.replaceFile();
	return 0;
}