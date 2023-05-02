/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 15:31:46 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/02 19:47:21 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap 
{
	protected :
		std::string			_name;
		long unsigned int	_hp;
		long unsigned int	_energy;
		long unsigned int	_damage;
		ClapTrap();											// default constructor
		void			noEnergy();
		void			noHP();

	public :
		ClapTrap(std::string name);
		~ClapTrap();										// default destructor
		ClapTrap(ClapTrap const & src);						// copy constructor

		ClapTrap	&operator=(ClapTrap const &src);	// assingation operator
		std::string	getName();
		void		setName(std::string);
		int			getHP();
		int			getEnergy();
		int			getDamage();
		void		attack(const std::string &target);
		void		takeDamage(int amount);
		void		beRepared(int amount);
};

std::ostream 	&operator<<(std::ostream &o, ClapTrap &ct);

#endif