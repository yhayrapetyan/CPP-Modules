/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:59:47 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/04 15:12:23 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>

class Zombie {
public:
	Zombie(std::string name);
	~Zombie(void);
	void announce(void);

private:
	std::string _name;
};

Zombie *newZombie(std::string name);

void randomChump(std::string name);

#endif