/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:28:38 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/04 18:49:11 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Changer.hpp"

int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Invalid number of arguments\n" << std::endl;
		return 1;
	}
	Changer changer(av[1]);
	changer.replace(av[2], av[3]);
	return 0;
}