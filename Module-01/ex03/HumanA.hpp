/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:15:45 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/04 17:43:33 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include  <iostream>
#include "Weapon.hpp"

typedef std::string string;

class HumanA
{
	public:
		HumanA(string name, Weapon &weapon);
		~HumanA(void);
		void	attack(void);

	private:
		string	_name;
		Weapon&	_weapon;
};

#endif