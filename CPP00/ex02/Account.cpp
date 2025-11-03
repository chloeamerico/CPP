/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:09:28 by camerico          #+#    #+#             */
/*   Updated: 2025/11/03 18:13:57 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

/*****************************************
*				Initialisation			 *
*			 des variables static		 *
*****************************************/

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*****************************************
*				Constructeur			 *
*			 (pour initialiser)			 *
*****************************************/

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
			<< "amount:" << this->_amount << ";"
			<< "created" << std::endl;
}


/*****************************************
*				Destructeur				 *
*		(pour terminer le programme)	 *
*****************************************/

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "closed" << std::endl;
}


/*****************************************************
*					   Les GETTERS				 	 *
*		pour retourner et acceder auc var static	 *
*****************************************************/


int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}


/*****************************************
*				Les fonctions			 *
*					Display				 *
*****************************************/

// fonction pour afficher le timestamp au debut de chaque ligne
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

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}

//const signifie qu'il ne modifie pas l'object
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

//une sorte de getter
int	Account::checkAmount(void) const
{
	return this->_amount;
}

//fonction qui effectue un deposit sur le compte
void Account::makeDeposit(int deposit)
{
	int old_amount = this->_amount;

	this->_amount = _amount + deposit;
	this->_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits += 1;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << old_amount << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

//fonction pour effectuer un retrait dans le compte
// 2 cas possibles : 
    // Retrait accepté : Assez d'argent dans le compte

    // Retrait refusé : Pas assez d'argent

bool	Account::makeWithdrawal(int withdrawal)
{

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";";
	
	if (this->_amount - withdrawal < 0)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}

	this->_amount = _amount - withdrawal;
	this->_nbWithdrawals += 1;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;
	
	std::cout << "withdrawal:" << withdrawal << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	
	return true;
}
