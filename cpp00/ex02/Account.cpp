/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:45:13 by jcrochet          #+#    #+#             */
/*   Updated: 2026/05/11 22:13:14 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts       = 0;
int Account::_totalAmount      = 0;
int Account::_totalNbDeposits  = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	: _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";created" << std::endl;
}

Account::~Account(void)
{
	_nbAccounts--;
	_totalAmount      -= this->_amount;
	_totalNbDeposits  -= this->_nbDeposits;
	_totalNbWithdrawals -= this->_nbWithdrawals;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";closed" << std::endl;
}

int Account::getNbAccounts(void)      { return (_nbAccounts); }
int Account::getTotalAmount(void)     { return (_totalAmount); }
int Account::getNbDeposits(void)      { return (_totalNbDeposits); }
int Account::getNbWithdrawals(void)   { return (_totalNbWithdrawals); }

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm *ltm = std::localtime(&now);

	std::cout << "[";
	std::cout << (1900 + ltm->tm_year)
			  << std::setfill('0') << std::setw(2) << (1 + ltm->tm_mon)
			  << std::setfill('0') << std::setw(2) << ltm->tm_mday
			  << "_"
			  << std::setfill('0') << std::setw(2) << ltm->tm_hour
			  << std::setfill('0') << std::setw(2) << ltm->tm_min
			  << std::setfill('0') << std::setw(2) << ltm->tm_sec;
	std::cout << "] ";
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:"    << _nbAccounts
			  << ";total:"      << _totalAmount
			  << ";deposits:"   << _totalNbDeposits
			  << ";withdrawals:"<< _totalNbWithdrawals
			  << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:"      << this->_accountIndex
			  << ";p_amount:"  << this->_amount
			  << ";deposit:"   << deposit;

	this->_amount         += deposit;
	this->_nbDeposits++;
	_totalAmount          += deposit;
	_totalNbDeposits++;

	std::cout << ";amount:"    << this->_amount
			  << ";nb_deposits:" << this->_nbDeposits
			  << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:"     << this->_accountIndex
			  << ";p_amount:" << this->_amount;

	if (withdrawal > this->_amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}

	this->_amount           -= withdrawal;
	this->_nbWithdrawals++;
	_totalAmount            -= withdrawal;
	_totalNbWithdrawals++;

	std::cout << ";withdrawal:"   << withdrawal
			  << ";amount:"       << this->_amount
			  << ";nb_withdrawals:" << this->_nbWithdrawals
			  << std::endl;
	return (true);
}

int Account::checkAmount(void) const
{
	return (this->_amount);
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:"        << this->_accountIndex
			  << ";amount:"      << this->_amount
			  << ";deposits:"    << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals
			  << std::endl;
}