/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:22:34 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/13 02:30:22 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <vector>
#include <fstream>
#include <cstdlib>

typedef short signed int sint;
typedef long signed int lint;
typedef std::vector<lint>::iterator date_iterator;

class Convert{
private:
	std::ifstream		CSV;
	std::vector<float>	value;
	std::vector<lint>	date;
	short unsigned int	index, len;
	
	Convert();
	Convert(Convert&);

	Convert& operator=(Convert&);

	void _Convert();
	void	reset_buffer();
	lint	eval_date(std::string, std::string);

	float cal_values(date_iterator&, float) const;
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