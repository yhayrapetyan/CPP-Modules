/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:44:25 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/03 19:18:55 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

# define CONTACT_HPP

# include <iostream>
# include <string>

typedef std::string string;

class	Contact
{
	private:
		string	_fname;
		string	_lname;
		string	_nick;
		string	_phone_num;
		string	_secret;
		
	public:
		Contact(void);
		~Contact(void);
		string		get_fname(void) const;
		string		get_lname(void) const;
		string		get_nick(void) const;
		string		get_phone_num(void) const;
		string		get_secret(void) const;
		void		set_fname(string str);
		void		set_lname(string str);
		void		set_nick(string str);
		void		set_phone_num(string str);
		void		set_secret(string str);
};

#endif