/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:30:21 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/04 19:33:57 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

#include <iostream>

typedef std::string string;

class Harl {
public:
	Harl(void);
	~Harl(void);
	void complain(string level);

private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif