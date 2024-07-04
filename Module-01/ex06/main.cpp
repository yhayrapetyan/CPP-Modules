/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:47:05 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/04 20:01:47 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl        harl;
    string	cmd = "";
    string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
      
	if (ac > 1)
		cmd = av[1];
    int i = 0;
    while (i < 4 and cmd.compare(levels[i]))
		i++;
    switch (i)
    {
        case 0:
            harl.complain(levels[0]);
        case 1:
            harl.complain(levels[1]);
        case 2:
            harl.complain(levels[2]);
        case 3:
            harl.complain(levels[3]);
            break;
        default: std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    return (0);
}