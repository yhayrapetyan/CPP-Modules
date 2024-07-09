/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:02:00 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/08 19:16:43 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

typedef std::string string;

class ClapTrap {
public:
	ClapTrap(void);
	~ClapTrap(void);
	ClapTrap(const ClapTrap &claptrap);
	ClapTrap& operator=(const ClapTrap &claptrap);
	ClapTrap(string name);

	void attack(const string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	string 	_name;
	int		_hit;
	int		_energy;
	int		_damage;
		
};

#endif