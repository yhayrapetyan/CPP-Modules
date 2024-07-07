/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:59:47 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/04 15:24:02 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>

class Zombie {
public:
	Zombie(void);
	~Zombie(void);
	void announce(void);
	void set_name(std::string name);

private:
	std::string _name;
};

Zombie *zombieHorde(int N, std::string name);

#endif