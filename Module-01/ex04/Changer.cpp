/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Changer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:39:31 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/04 19:25:23 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Changer.hpp"

Changer::Changer(string filename)
{
	this->_filename = filename;
}

Changer::~Changer(void)
{
}

void Changer::replace(string to_change, string value)
{
	std::ifstream   infile(this->_filename);
    std::string     content;
    size_t          pos = 0;
    size_t          i = 0;

	if (!infile.is_open()){
		std::cerr << "No Such File" << std::endl;
		infile.close();
		exit(1);
	}
    if (getline(infile, content, '\0')){
		std::ofstream   outfile(this->_filename + ".replace");
        while (1)
        {
            pos = content.find(to_change, i);
            if (pos == std::string::npos)
                break;
            content.erase(pos, to_change.length());
            content.insert(pos, value);
            i = pos + value.length();
        }
        outfile << content;
        outfile.close();
		infile.close();

    }
    else{
		std::cerr << "Empty File" << std::endl;
		infile.close();
		exit(1);
	}
}
