/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:36:00 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/29 20:45:03 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_CLASS_HPP
# define REPLACE_CLASS_HPP

#include <string>
#include <fstream>
#include <iostream>

# define RED    "\033[97;101m"
# define RES    "\033[0m"

class	Replace{

private:
	const	std::ifstream	*in;
	const	std::ofstream	*out;
	std::string		s1;
	std::string		s2;

public:
	Replace(void);
	Replace(const std::ifstream &infile, const std::ofstream &outfile, std::string s1, std::string s2);
	~Replace(void);
	void	replaceFile(void) const;
};

void	error(std::string msg);

#endif