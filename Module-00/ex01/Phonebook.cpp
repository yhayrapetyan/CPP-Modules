/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:57:24 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/08 14:07:21 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void) {
	this->_index = 0;
	std::cout << "Welcome" << std::endl;
}

Phonebook::~Phonebook(void) {
	std::cout << "See you soon!" << std::endl;
}

string	get_input(string prompt) {

	string str = "";
	
	std::cout << prompt;
	std::getline(std::cin, str);
	return str;
}

void Phonebook::add(void) {
	string str;

	str = "";
	if (this->_index > 7)
		std::cout << "Warning: overwriting info about " << this->_contacts[this->_index % 8].get_fname() << std::endl;
	while (!std::cin.eof() && \
			this->_contacts[this->_index % 8].set_fname(get_input("Enter a first name: ")) == false)
			;
	while (!std::cin.eof() && \
			this->_contacts[this->_index % 8].set_lname(get_input("Enter last name: ")) == false)
			;
	while (!std::cin.eof() && \
			this->_contacts[this->_index % 8].set_nick(get_input("Enter nickname: ")) == false)
			;
	while (!std::cin.eof() && \
			this->_contacts[this->_index % 8].set_phone_num(get_input("Enter phone number: ")) == false)
			;
	while (!std::cin.eof() && \
			this->_contacts[this->_index % 8].set_secret(get_input("Enter darkest secret: ")) == false)
			;

	std::cout << this->_contacts[this->_index % 8].get_fname() << \
                " successfully added to phonebook [" << this->_index % 8 + 1 << "/8]" << std::endl;
	this->_index++;
}


string add_spaces(int n) {
	string str;

	while (n--)
		str.append(" ");
	return (str);
}

string fix_width(string str, unsigned long max) {
	if (str.size() > max) {
		str.resize(max);
		str[str.size() - 1] = '.';
	}
	return (str);
}

int search_id(Contact contacts[8]) {
	char c;
	int i;
	string str;

	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	c = '0';
	i = 0;
	while (++c <= '8') {
		if (contacts[c - 1 - '0'].get_fname().size() && ++i) {
			str = c;
			str = fix_width(str, 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = fix_width(contacts[c - 1 - '0'].get_fname(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = fix_width(contacts[c - 1 - '0'].get_lname(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = fix_width(contacts[c - 1 - '0'].get_nick(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			std::cout << "|" << std::endl;
		}
	}
	std::cout << " ------------------------------------------- " << std::endl;
	return (i);
}

void Phonebook::print(Contact contact) {
	std::cout << std::endl << "Requesting contact information..." << std::endl;
	if (!contact.get_fname().size()) {
		std::cout << "Failed to get info for this contact" << std::endl;
		return;
	}
	std::cout << "First Name: " << contact.get_fname() << std::endl;
	std::cout << "Last Name: " << contact.get_lname() << std::endl;
	std::cout << "Nickname: " << contact.get_nick() << std::endl;
	std::cout << "Phone Number: " << contact.get_phone_num() << std::endl;
	std::cout << "Darkest Secret: " << contact.get_secret() << std::endl;
}

void Phonebook::search(void) {
	string str;

	str = "";
	if (!search_id(this->_contacts)) {
		std::cout << std::endl << "Phonebook is empty!" << std::endl;
		return;
	}
	while (!std::cin.eof()) {
		std::cout << "Select an index: ";
		if (std::getline(std::cin, str) && str != "") {
			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && \
                    this->_contacts[str[0] - 1 - '0'].get_fname().size())
				break;
		}
		if (str != "")
			std::cout << "Invalid index!" << std::endl;
	}
	if (!std::cin.eof())
		this->print(this->_contacts[str[0] - 1 - '0']);
}