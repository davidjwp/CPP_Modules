/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 21:09:15 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/24 23:20:21 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

template <typename T, typename N>
class Span{
private:
	T [] content;
	unsigned int N;	
public:

	Span();
	Span(unsigned int);
	~Span();

	Span& operator=(Span&);
	addNumber();
	shortestSpan();
	longestSpan();
};



#endif