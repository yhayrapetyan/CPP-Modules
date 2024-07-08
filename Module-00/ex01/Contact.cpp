/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:43:25 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/08 14:07:49 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	return;
}

Contact::~Contact(void) {
	return;
}

string Contact::get_fname(void) const {
	return (this->_fname);
}

string Contact::get_lname(void) const {
	return (this->_lname);
}

string Contact::get_nick(void) const {
	return (this->_nick);
}

string Contact::get_phone_num(void) const {
	return (this->_phone_num);
}

string Contact::get_secret(void) const {
	return (this->_secret);
}

bool	isAlpha(string str) {
	for (int i = 0; str[i]; i++) {
		if (!isalpha(str[i]))
			return false;
	}
	return true;
}

bool	isDigit(string str) {
	for (int i = 0; str[i]; i++) {
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

bool Contact::set_fname(string str) {
	if (str == "")
		return false;
	if (isAlpha(str)) {
		this->_fname = str;
		return true;
	}
	else {
		std::cout << "Error not valid first name\n";
		return false;	
	}
}

bool Contact::set_lname(string str) {
	if (str == "")
		return false;
	if (isAlpha(str)) {
		this->_lname = str;
		return true;
	}
	else {
		std::cout << "Error not valid last name\n";
		return false;
	}
}

bool Contact::set_nick(string str) {
	if (str == "")
		return false;
		this->_nick = str;
	return true;
} 

bool Contact::set_phone_num(string str) {
	if (str == "")
		return false;
	if (isDigit(str)) {
		this->_phone_num = str;
		return true;
	}
	else {
		std::cout << "Error not valid number\n";
		return false;
	}
}

bool Contact::set_secret(string str) {
	if (str == "")
		return false;
	this->_secret = str;
	return true;
}