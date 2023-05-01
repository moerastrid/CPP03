/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: astrid <astrid@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 14:13:37 by astrid        #+#    #+#                 */
/*   Updated: 2023/05/01 14:37:25 by astrid        ########   odam.nl         */
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
};

#endif