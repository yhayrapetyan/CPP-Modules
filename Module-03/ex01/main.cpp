/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:28:25 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/05 20:31:18 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap    Kenpachi("Clap1");
	ClapTrap    Unohana("Clap2");
	ScavTrap    Ulquiorra("Scav1");

	Kenpachi.attack("Clap2");
	Unohana.takeDamage(10);
	Unohana.beRepaired(1);
	Ulquiorra.guardGate();
	Ulquiorra.attack("Clap1");
	Kenpachi.takeDamage(10);
	Ulquiorra.attack("Clap2");
	Unohana.takeDamage(100);
	return (0);
}
