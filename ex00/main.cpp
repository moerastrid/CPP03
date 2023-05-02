/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 15:32:42 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/02 19:48:53 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void) {
	ClapTrap b("erwt");
	ClapTrap a("PinO");

	a.attack("me");
	a.takeDamage(4);
	a.beRepared(1);
	a.beRepared(-1);
	a.attack("b");
	b.attack("you");
	b.takeDamage(9);
	b.takeDamage(-6);
	b.beRepared(2);
	b.beRepared(2);
	b.beRepared(2);
	b.beRepared(2);
	b.beRepared(2);
	b.beRepared(2);
	b.beRepared(2);
	b.beRepared(2);
	b.beRepared(2);
	b.beRepared(2);
	b.beRepared(2);	
	std::cout << "ct: " << a << std::endl;
	std::cout << "ct: " << b << std::endl;
}
