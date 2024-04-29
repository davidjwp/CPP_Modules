/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:22:34 by djacobs           #+#    #+#             */
/*   Updated: 2024/04/29 21:48:04 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <list>
#include <fstream>
#include <cstdlib>

typedef short signed int sint;
typedef long int lint;
typedef std::list<lint>::iterator date_iterator;

class BitcoinExchange{
private:
	std::ifstream		CSV;
	std::list<float>	value;
	std::list<lint>	date;
	
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange&);

	BitcoinExchange& operator=(BitcoinExchange&);

	void _BitcoinExchange();
	void	reset_buffer();
	lint	eval_date(std::string, std::string);

	float cal_values(std::list<lint>::iterator, float);
	lint	encode(sint,sint,sint);

public:
	~BitcoinExchange();
	BitcoinExchange(std::ifstream&);

};

class Error: public std::exception{
private:
	std::string _msg;

public:
	Error();
	virtual ~Error() throw();
	Error(const Error&);
	Error(const char*);
	Error& operator=(const Error&);
	virtual const char* what() const throw();
};

//functor for the std::min_element function since i need to decode the date before using it
class Smallest{
private:
	lint	_target;

public:

	Smallest();
	virtual ~Smallest();
	Smallest(const Smallest&);
	Smallest(const lint target);
	bool operator()(lint, lint) const;
	Smallest& operator=(const Smallest&);
};

#endif