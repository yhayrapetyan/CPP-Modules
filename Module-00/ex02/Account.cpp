/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:08:15 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/04 14:28:46 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_accountsNb = 0;
int	Account::_totalAmount = 0;
int	Account::_totalDepositsNb = 0;
int	Account::_totalWithdrawalsNb = 0;
		
Account::Account(int start_deposit)
{
	this->_index = this->getAccountsNb();
	this->_amount = start_deposit;
	this->_depositsNb = 0;
	this->_withdrawalsNb = 0;
	Account::_totalAmount += start_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_index;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;
	Account::_accountsNb++;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_index; 
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;
	Account::_accountsNb--;
}

void	Account::_displayTimestamp(void)
{
	time_t	now;

	now = time(NULL);
	std::cout << std::put_time(localtime(&now), "[%Y%m%d_%H%M%S] ");
}

int	Account::getAccountsNb(void){return Account::_accountsNb;}
int	Account::getTotalAmount(void){return Account::_totalAmount;}
int Account::getDepositsNb(void){return Account::_totalDepositsNb;}
int	Account::getWithdrawalsNb(void){return Account::_totalWithdrawalsNb;}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getAccountsNb();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getDepositsNb();
	std::cout << ";withdrawals:" << Account::getWithdrawalsNb() << std::endl;
}

void	Account::displayStatus(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_index;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits" << this->_depositsNb;
	std::cout << ";withdrawals:" << this->_withdrawalsNb << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_depositsNb++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_index;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->_amount + deposit;
	std::cout << ";nb_deposits:" << this->_depositsNb << std::endl;
	this->_amount += deposit;
	Account::_totalDepositsNb++;
	Account::_totalAmount += deposit;	
}
bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_index;
	std::cout <<";p_amount:" << this->_amount;
	std::cout << ";withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_withdrawalsNb++;
	Account::_totalWithdrawalsNb++;
	std::cout << withdrawal;
	std::cout << ";amount:" << this->_amount - withdrawal;
	std::cout << ";nb_withdrawals:" << this->_withdrawalsNb << std::endl;
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	return (true);
}