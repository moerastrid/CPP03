/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 15:32:42 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/02 19:52:07 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	ScavTrap Serena("Serena");
	ScavTrap Copycat = Serena;
	Copycat.setName("Copycat");
	ScavTrap Serano(Serena);
	Serano.setName("Serano");
	ScavTrap a("AÀÁÄÂÆÃÅĀ");
	ScavTrap group[] = {Serena, Copycat, Serano, a};

	int	i = 0;
	while (Serena.getHP() != 0)
	{
		group[i % 4].guardGate();
		Serena.attack("Copycat");
		Copycat.takeDamage(20);
		a.attack("Serena");
		Serena.takeDamage(20);
		Serano.beRepared(5);
		Copycat.attack("Serena");
		Serena.takeDamage(20);
		Serena.beRepared(10);
		i++;
	}
	Serena.beRepared(10);
	Serena.beRepared(10);
	std::cout << "Hi this is " << Serena << std::endl;
	std::cout << "Hi this is " << Copycat << std::endl;
	std::cout << "Hi this is " << Serano << std::endl;
	std::cout << "Hi this is " << a << std::endl;
}
