/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:43:25 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/03 18:29:20 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

string	Contact::get_fname(void) const
{
	return (this->_fname);
}

string	Contact::get_lname(void) const
{
	return (this->_lname);
}

string	Contact::get_nick(void) const
{
	return (this->_nick);
}

string	Contact::get_phone_num(void) const
{
	return (this->_phone_num);
}

string	Contact::get_secret(void) const
{
	return (this->_secret);
}

void	Contact::set_fname(std::string str)
{
	this->_fname = str;
}

void	Contact::set_lname(std::string str)
{
	this->_lname = str;
}

void	Contact::set_nick(std::string str)
{
	this->_nick = str;
}

void	Contact::set_phone_num(std::string str)
{
	this->_phone_num = str;
}

void	Contact::set_secret(std::string str)
{
	this->_secret = str;
}