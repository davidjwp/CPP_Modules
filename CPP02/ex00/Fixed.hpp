/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:14:14 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/02 18:03:28 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class	Fixed{

private:
	int	_raw;
	static const int _nbits = 8;

public:	
	Fixed(void);//									<-default construtor
	Fixed(const Fixed &instance);//					<-copy constructor
	~Fixed(void);//									<-destructor

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	Fixed	&operator=(const Fixed &instance);//	<-assignement operator
};