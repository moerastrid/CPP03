/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/25 18:04:03 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/02 15:44:02 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_name = "default";
	this->_hp = 100;
	this->_energy = 50;
	this->_damage = 20;
}

// P U B L I C

ScavTrap::ScavTrap(std::string *name) {
	std::cout << "\033[1;32m" << "ScavTrap constructor(*name) called" << "\033[0m" << std::endl;
	if (name == NULL)
		this->_name = "NULL";
	this->_hp = 100;
	this->_energy = 50;
	this->_damage = 20;
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "\033[1;32m" << "ScavTrap constructor(name) called, creating: " << name << "\033[0m" << std::endl;
	this->_name = name;
	this->_hp = 100;
	this->_energy = 50;
	this->_damage = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "\033[1;31m" << "ScavTrap " << this->_name << ": default destructor called" << "\033[0m" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &src)
{
	std::cout << "\033[1;34m" << "ScavTrap '=' sign operator called" << "\033[0m" << std::endl;
	this->_name = src._name;
	this->_hp = src._hp;
	this->_energy = src._energy;
	this->_damage = src._damage;
	return (*this);
}

ScavTrap::ScavTrap(ScavTrap const &src) {
	std::cout << "\033[1;34m" << "ScavTrap copy constructor called" << "\033[0m" << std::endl;
	*this = src;
}

void	ScavTrap::guardGate(void) {
	std::cout << "\033[1;33m" << "ScavTrap " << this->_name << " is now in Gate keeper mode" << "\033[0m" << std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	if (this->_hp == 0)
		return (this->noHP());
	if (this->_energy-- == 0)
		return (this->noEnergy());
	std::cout << "\033[1;35m" << "ScavTrap " << this->_name << " attacks " << target << ", causing ";
	std::cout << this->_damage << " points of damage!" << "\033[0m" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	if (this->_hp == 0)
		return (this->noHP());
	this->_hp -= amount;
	if (this->_hp < 0)
		this->_hp = 0;
	std::cout << "\033[1;36m" << "ScavTrap " << this->_name << " takes " << amount;
	std::cout << " damage, it has " << this->_hp << " HP left!" << "\033[0m" << std::endl;
}

void	ScavTrap::beRepared(unsigned int amount) {
	if (this->_hp == 0)
		return (this->noHP());
	if (this->_energy-- == 0)
		return (this->noEnergy());
	this->_hp += amount;
	if (this->_hp > MAX_HP)
		this->_hp = MAX_HP;
	std::cout << "\033[1;30m" << "ScavTrap " << this->_name << " repairs itself with " << amount << ", it now has ";
	if (this->_hp != MAX_HP)
		std::cout << this->_hp << " HP!" << "\033[0m" << std::endl;
	else
		std::cout << MAX_HP << "(max) HP!" << "\033[0m" << std::endl;
}