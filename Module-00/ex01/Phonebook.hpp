/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:56:37 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/03 19:17:56 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

#include "Contact.hpp"

class	Phonebook {
public:
	Phonebook(void);
	~Phonebook(void);
	void	add(void);
	void	search(void);
	void	print(Contact contact);

private:
	Contact	_contacts[8];
	int		_index;
};



#endif