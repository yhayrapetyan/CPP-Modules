/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:38:04 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/08 13:26:23 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void) {
	Phonebook phonebook;
	string str;

	while (str != "EXIT") {
		std::cout << "Enter command: ADD, SEARCH, EXIT;\n";
		std::getline(std::cin, str);
		if (str == "ADD")
			phonebook.add();
		else if (str == "SEARCH")
			phonebook.search();
		if (std::cin.eof()) {
			std::cout << std::endl;
			return 0;
		}
	}
	return 0;
}