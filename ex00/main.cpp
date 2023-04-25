/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 15:32:42 by ageels        #+#    #+#                 */
/*   Updated: 2023/04/25 17:55:03 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void) {
	ClapTrap b("erwt");
	ClapTrap a(NULL);

	a.attack("me");
	a.takeDamage(4);
	a.beRepared(1);
	a.attack("b");
	b.attack("you");
	b.takeDamage(9);
	b.beRepared(-1);
	std::cout << "ct: " << a << std::endl;
	std::cout << "ct: " << b << std::endl;
}
