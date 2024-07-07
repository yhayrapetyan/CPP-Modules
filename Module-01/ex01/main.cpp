/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:13:56 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/04 15:26:22 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie *Z;
	int n = 4;

	Z = zombieHorde(n, "Some Name");

	for (int i = 0; i < n; i++)
		Z[i].announce();

	delete[] Z;
	return (0);
}