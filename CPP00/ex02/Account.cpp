/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:09:28 by camerico          #+#    #+#             */
/*   Updated: 2025/10/29 17:24:18 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

//on initialise les variables statics

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	std::time_t	t = std::time(NULL);
	std::tm		*now = std::localtime(&t);

	std::cout << "["
			<< (now->tm_year + 1900)
			<< std::setfill('0') << std::setw(2) << (now->tm_mon + 1)
			<< std::setfill('0') << std::setw(2) << now->tm_mday
			<< "_"
			<< std::setfill('0') << std::setw(2) << now->tm_hour
			<< std::setfill('0') << std::setw(2) << now->tm_min
			<< std::setfill('0') << std::setw(2) << now->tm_sec
			<< "] ";
}

//on initialise avec le constructeur

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += initial_deposit;
	
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			<< "amount:" << 
}
