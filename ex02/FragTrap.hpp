/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: astrid <astrid@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 14:13:37 by astrid        #+#    #+#                 */
/*   Updated: 2023/05/02 15:45:41 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    private :
        FragTrap();
    
    public :
        FragTrap(std::string name);
        FragTrap(std::string *ptr);
        ~FragTrap();
        FragTrap(FragTrap const & src);
        FragTrap    &operator=(FragTrap const &src);

        void highFivesGuys(void);
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepared(unsigned int amount);
};

#endif