/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 15:31:46 by ageels        #+#    #+#                 */
/*   Updated: 2023/04/20 15:56:27 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap 
{
	private :
		std::string		_name;
		int				_hp;
		int				_energy;
		int				_damage;

		ClapTrap();											// default constructor

	public :
		ClapTrap(std::string name);
		~ClapTrap();										// default destructor
		ClapTrap(ClapTrap const & src);						// copy constructor

		ClapTrap		&operator=(ClapTrap const &rhs);	// assingment operator
		void			setname(std::string newname);
		std::string		getname(void);
};

#endif