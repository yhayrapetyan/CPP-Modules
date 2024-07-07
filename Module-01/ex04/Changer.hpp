/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Changer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:36:25 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/04 19:15:25 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANGER_H
# define CHANGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <filesystem>

typedef std::string string;

class Changer {
public:
	Changer(string filename);
	~Changer(void);
	void replace(string to_change, string value);

private:
	string _filename;
};

#endif