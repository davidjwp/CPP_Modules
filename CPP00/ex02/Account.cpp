/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:51:15 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/28 13:39:55 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void){}

Account::~Account(void){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "closed" << std::endl;
}

Account::Account(int deposit){
	Account::_displayTimestamp();
	this->_nbDeposits = 0;
	this->_accountIndex = Account::_nbAccounts++;
	this->_amount = deposit;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += deposit;
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "created" << std::endl;
}

int	Account::getNbAccounts(void){
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void){
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void){
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void){
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void){
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ';';
	std::cout << "total:" << getTotalAmount() << ';';
	std::cout << "deposits:" << getNbDeposits() << ';';
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ':';
	std::cout << "p_amount:" << this->_amount << ':';
	this->_amount += deposit;
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;
	std::cout << "deposit:" << deposit << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ':';
	std::cout << "p_amount:" << this->_amount << ':';
	if (withdrawal <= this->_amount && withdrawal > 0){
		
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals += 1;
		std::cout << "withdrawal:" << withdrawal << ';';
		std::cout << "amount:" << this->_amount << ';';
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	}
	std::cout << "withdrawal:" << "refused" << std::endl;
	return false;
}

int	Account::checkAmount(void) const{
	return this->_amount;
}

void	Account::displayStatus(void) const{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->checkAmount() << ';';
	std::cout << "deposits:" << this->_nbDeposits << ';';
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl; 
}

void	Account::_displayTimestamp(void){
	std::time_t raw;
	time(&raw);
	std::tm 	*local = localtime(&raw);
	char		buf[42];
	strftime(buf, 42, "[%Y%m%e_%H%M%S] ", local);

	std::cout << buf; 
}
