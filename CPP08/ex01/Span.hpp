/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 21:09:15 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/25 20:39:40 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iterator>

typedef std::vector<int>::iterator IT;

class Span{
private:
	Span();
	unsigned int _curr;
	unsigned int _size;
	std::vector<int> _vec;
public:
	Span(const Span&);
	Span(unsigned int);
	~Span();

	Span& operator=(Span&);
	void addNumber(int);
	class SpanSizeReached: public std::exception{
	public:
		const char* what() const throw(){return "Span size reached";}	
	};
	void insert(IT, IT);
	unsigned int shortestSpan();
	unsigned int longestSpan() const;
	unsigned int getSize() const;
	std::vector<int> getVec() const;
	unsigned int getCurr() const;
};

#endif