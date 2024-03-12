/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidjwp <davidjwp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:26:48 by davidjwp          #+#    #+#             */
/*   Updated: 2024/03/08 05:11:02 by davidjwp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
#include <stdlib.h>

class EC{
private:
	EC();
	~EC();
	EC(EC& cpy);

	virtual EC& operator=(EC&) = 0;
public:
	class FileNotGiven: public std::exception{
	public:
		const char* what() const throw(){ return "no file given";}
	};
	class CannotOpenFile: public std::exception{
	public:
		const char* what() const throw(){ return "could not open file";}
	};
};

int	main(int ac, char **av){
	try {
		if (ac < 2) EC::FileNotGiven();
		
		
		std::ofstream input_file;
		std::ofstream CSV;
		
		CSV.open("data.csv");
		input_file.open(av[1]);
		if (!input_file.is_open()) EC::CannotOpenFile();
		if (input_file.)
		
	}
	catch (std::exception& E){ std::cout << "Error: " << E.what() << std::endl; return 1;}
	return 0;
}
