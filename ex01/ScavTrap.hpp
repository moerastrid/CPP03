/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/25 18:05:06 by ageels        #+#    #+#                 */
/*   Updated: 2023/04/25 21:19:10 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private :
	ScavTrap();											// default constructor

	public :
	ScavTrap(std::string name);
	ScavTrap(std::string *str);
	~ScavTrap();										// default destructor
	ScavTrap(ScavTrap const & src);						// copy constructor

	ScavTrap		&operator=(ScavTrap const &src);	// assingation operator
	void			guardGate(void);
};

#endif