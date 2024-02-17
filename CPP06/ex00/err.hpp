/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:20:38 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/17 17:06:42 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_HPP
# define ERR_HPP

# include <exception>

class err{
private:
	err();
	err(err&);
	virtual ~err() = 0;

	virtual err& operator=(err&) = 0;
public:
	class char_BadInput: public std::exception{
		const char* what()const throw(){ return "bad char definition";}
	};

	class UnknownInput: public std::exception{
		const char* what()const throw(){ return "unknown input";}
	};
};

err::err(){}
err::err(err& cpy){static_cast<void>(cpy);}

#endif