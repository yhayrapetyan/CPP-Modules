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

int main() {
	ClapTrap Kenpachi("Kenpachi Zaraki");
	ClapTrap Unohana("Retsu Unohana");

	Kenpachi.attack("Retsu Unohana");
	Unohana.takeDamage(7);
	Unohana.beRepaired(1);
	return (0);
}
