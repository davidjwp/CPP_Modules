/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:51:15 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/27 19:58:26 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(void){
	return ;
}

Account::Account(int deposit){
	Account::_nbDeposits += 1;
	Account::_amount = deposit;
	return ;
}

Account::~Account(void){
	return ;
}

int	Account::getNbAccounts(void){
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void){
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void){
	return (Account::_nbDeposits);
}


//public:

//	typedef Account		t;

//	static int	getNbAccounts( void );
//	static int	getTotalAmount( void );
//	static int	getNbDeposits( void );
//	static int	getNbWithdrawals( void );
//	static void	displayAccountsInfos( void );

//	Account( int initial_deposit );
//	~Account( void );

//	void	makeDeposit( int deposit );
//	bool	makeWithdrawal( int withdrawal );
//	int		checkAmount( void ) const;
//	void	displayStatus( void ) const;


//private:

//	static int	_nbAccounts;
//	static int	_totalAmount;
//	static int	_totalNbDeposits;
//	static int	_totalNbWithdrawals;

//	static void	_displayTimestamp( void );

//	int				_accountIndex;
//	int				_amount;
//	int				_nbDeposits;
//	int				_nbWithdrawals;

//	Account( void );

//};

