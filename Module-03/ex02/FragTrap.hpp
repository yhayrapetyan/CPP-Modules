#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &fragtrap);
		FragTrap& operator=(const FragTrap &fragtrap);
		virtual ~FragTrap();

		void    highFivesGuys();
};

#endif