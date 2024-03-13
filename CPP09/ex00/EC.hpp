/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EC.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:37:24 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/12 21:28:49 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EC_HPP
# define EC_HPP

#include <exception>

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
	class MissingDate: public std::exception{
	public:
		const char* what() const throw(){ return "CSV is missing a date";}
	};
	class MissingValue: public std::exception{
	public:
		const char* what() const throw(){ return "CSV is missing a value";}
	};
};

#endif