/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 15:32:42 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/02 15:49:03 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	FragTrap Frag("Fragger");
	FragTrap Frog = Frag;
	Frog.setName("Frogger");
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

	std::cout << std::endl << "Hi this is " << Frag << std::endl;
	std::cout << "Hi this is " << Frog << std::endl;
	std::cout << "Hi this is " << Sarah << std::endl << std::endl;
}
