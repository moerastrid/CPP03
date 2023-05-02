/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: astrid <astrid@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 14:13:37 by astrid        #+#    #+#                 */
/*   Updated: 2023/05/02 20:00:40 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private :
		FragTrap();										// default constructor
		void	noEnergy();
		void	noHP();

	public :
		FragTrap(std::string name);
		~FragTrap();									// default destructor
		FragTrap(FragTrap const & src);					// copy constructor

		FragTrap	&operator=(FragTrap const &src);	// assingation operator
		void		highFivesGuys();
		void		attack(const std::string &target);
		void		takeDamage(int amount);
		void		beRepared(int amount);
};

#endif