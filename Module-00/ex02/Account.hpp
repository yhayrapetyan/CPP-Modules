/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:54:27 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/04 14:27:02 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCOUNT_H
# define ACCOUNT_H

#include <iostream>
#include <ctime>
#include <iomanip>

class Account 
{	
	
	public:
		typedef Account		t;
		
		Account(int	start_deposit);
		~Account(void);
		
		static void	displayAccountsInfos(void);
		static int	getAccountsNb(void);
		static int	getTotalAmount(void);
		static int	getDepositsNb(void);
		static int	getWithdrawalsNb(void);
		
		bool	makeWithdrawal(int withdrawal);
		void	makeDeposit(int deposit);
		void	displayStatus(void);

	private:
		static void _displayTimestamp(void);
		static int _accountsNb;
		static int	_totalAmount;
		static int	_totalDepositsNb;
		static int	_totalWithdrawalsNb;
		int			_index;
		int			_amount;
		int			_depositsNb;
		int			_withdrawalsNb;
};

#endif