/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:22:34 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/17 00:58:00 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <list>
#include <fstream>
#include <cstdlib>

typedef short signed int sint;
typedef long int lint;
typedef std::list<lint>::iterator date_iterator;

class Convert{
private:
	std::ifstream		CSV;
	std::list<float>	value;
	std::list<lint>	date;
	short unsigned int	index, len;
	
	Convert();
	Convert(Convert&);

	Convert& operator=(Convert&);

	void _Convert();
	void	reset_buffer();
	lint	eval_date(std::string, std::string);

	//float cal_values(date_iterator&, float) const;
	float cal_values(std::list<lint>::iterator, float);
	lint	encode(sint,sint,sint);

	class Smallest{
	private:
		lint	_target;
	public:
		Smallest(unsigned int target): _target(target){}
		bool operator()(lint A, lint B) const{return std::abs(A - _target) < std::abs(B - _target);}
	};
public:
	~Convert();
	Convert(std::ifstream&);

};

#endif