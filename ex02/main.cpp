/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 15:32:42 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/01 14:45:50 by astrid        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	FragTrap Frag("Frag");
	FragTrap Frog = Frag;
	Frog.setName("Frog");
	FragTrap Sarah("Sally");
	FragTrap group[3] = {Frag, Frog, Sarah};

	int	i = 0;
	while (Sarah.getHP() != 0)
	{
		group[i % 3].highFivesGuys();
		Sarah.attack("Frag");
		Frag.takeDamage(30);
		Frog.attack("Sarah");
		Sarah.takeDamage(30);
		Frag.beRepared(5);
		Frag.attack("Frog");
		Sarah.takeDamage(30);
		Sarah.beRepared(50);
		i++;
	}

	std::cout << "Hi this is " << Frag << std::endl;
	std::cout << "Hi this is " << Frog << std::endl;
	// std::cout << "Hi this is " << Serena << std::endl;
	// std::cout << "Hi this is " << Copycat << std::endl;
	// std::cout << "Hi this is " << Serano << std::endl;
	// std::cout << "Hi this is \t" << a << std::endl;
}

//void		(Harl::*harlptr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
//	std::string	complaints[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
