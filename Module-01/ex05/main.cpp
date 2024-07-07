/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:47:05 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/04 19:48:25 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void) {
	Harl harl;
	std::string cmd;

	std::cout << "Usage: " << "DEBUG " << "INFO " << "WARNING " << "ERROR " << "EXIT" << std::endl;
	while (true) {
		std::getline(std::cin, cmd);
		if (std::cin.eof()) {
			std::cout << "Exited" << std::endl;
			return (1);
		}
		if (cmd == "EXIT")
			return (0);
		harl.complain(cmd);
	}
	return (0);
}