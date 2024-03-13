/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:22:34 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/13 01:06:42 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <vector>
#include <fstream>

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

	template <typename T>
	class Smallest{
	private:
		T	_target;
	public:
		Smallest(T target): _target(target){}
		bool smaller(T A,T B) const{return (T - target) < (B - target);}
	};
public:
	~Convert();
	Convert(std::ifstream&);

};

#endif