/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:22:34 by djacobs           #+#    #+#             */
/*   Updated: 2024/04/10 16:03:59 by djacobs          ###   ########.fr       */
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
	lint	eval_date(std::string, std::string, unsigned short int);

	float cal_values(std::list<lint>::iterator, float);
	lint	encode(sint,sint,sint);

	//functor for the std::min_element function since i need to decode the date before using it
	class Smallest{
	private:
		lint	_target;
	public:
		Smallest(unsigned int target): _target(target){}
		bool operator()(lint A, lint B) const{return std::abs(A - _target) < std::abs(B - _target);}
	};
	class FilebadDay: public std::exception{
		std::string	_File;
	public:
		virtual ~FilebadDay() throw(){}
		FilebadDay(std::string file): _File(file + " file date wrong"){}
		const char* what() const throw(){ return _File.c_str();}
	};
	class FileBadValue: public std::exception{
		std::string	_File;
	public:
		virtual ~FileBadValue() throw(){}
		FileBadValue(){}
		FileBadValue(std::string file): _File(file + " file value wrong"){}
		const char* what() const throw(){ return _File.c_str();}
	};
public:
	class FileNotGiven: public std::exception{
	public:
		const char* what() const throw(){ return "no file given";}
	};
	class CannotOpenFile: public std::exception{
	public:
		const char* what() const throw(){ return "could not open file";}
	};
	~BitcoinExchange();
	BitcoinExchange(std::ifstream&);

};

#endif