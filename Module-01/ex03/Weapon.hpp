/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:06:08 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/04 17:37:45 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

typedef std::string string;

class Weapon {
public:
	Weapon(string type);
	~Weapon(void);
	string getType(void);
	void setType(string type);

private:
	string _type;
};


#endif