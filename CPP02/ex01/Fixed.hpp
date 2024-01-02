/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:14:14 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/02 17:58:12 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class	Fixed{

private:
	int	_raw;
	static const int _nbits = 8;

public:	
	Fixed(void);
	Fixed(const int val);
	Fixed(const Fixed &instance);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	Fixed	&operator=(const Fixed &instance);
};