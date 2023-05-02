/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 15:31:46 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/02 16:09:37 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

#define MAX_HP 1000

class ClapTrap 
{
	private :
		std::string			_name;
		long unsigned int	_hp;
		long unsigned int	_energy;
		long unsigned int	_damage;
		ClapTrap();											// default constructor
		void			noEnergy(void);
		void			noHP(void);

	public :
		//ClapTrap(std::string const &name); 
		ClapTrap(std::string name);
		ClapTrap(std::string *name);
		~ClapTrap();										// default destructor
		ClapTrap(ClapTrap const & src);						// copy constructor

		ClapTrap		&operator=(ClapTrap const &src);	// assingation operator
		std::string		getName(void);
		int				getHP(void);
		int				getEnergy(void);
		int				getDamage(void);
		void			attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepared(unsigned int amount);
};

std::ostream 	&operator<<(std::ostream &o, ClapTrap &ct);

#endif