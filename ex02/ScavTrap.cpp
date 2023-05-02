/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/25 18:04:03 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/02 15:45:17 by ageels        ########   odam.nl         */
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
	std::cout<< "ScavTrap constructor(*name) called" << std::endl;
	if (name == NULL)
		this->_name = "NULL";
	this->_hp = 100;
	this->_energy = 50;
	this->_damage = 20;
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "ScavTrap constructor(name) called, creating: " << name << std::endl;
	this->_name = name;
	this->_hp = 100;
	this->_energy = 50;
	this->_damage = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << ": default destructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &src)
{
	std::cout << "ScavTrap '=' sign operator called" << std::endl;
	this->_name = src._name;
	this->_hp = src._hp;
	this->_energy = src._energy;
	this->_damage = src._damage;
	return (*this);
}

ScavTrap::ScavTrap(ScavTrap const &src) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	if (this->_hp == 0)
		return (this->noHP());
	if (this->_energy-- == 0)
		return (this->noEnergy());
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing ";
	std::cout << this->_damage << " points of damage!" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	if (this->_hp == 0)
		return (this->noHP());
	this->_hp -= amount;
	if (this->_hp < 0)
		this->_hp = 0;
	std::cout << "ScavTrap " << this->_name << " takes " << amount;
	std::cout << " damage, it has " << this->_hp << " HP left!" << std::endl;
}

void	ScavTrap::beRepared(unsigned int amount) {
	if (this->_hp == 0)
		return (this->noHP());
	if (this->_energy-- == 0)
		return (this->noEnergy());
	this->_hp += amount;
	if (this->_hp > MAX_HP)
		this->_hp = MAX_HP;
	std::cout << "ScavTrap " << this->_name << " repairs itself with " << amount << ", it now has ";
	if (this->_hp != MAX_HP)
		std::cout << this->_hp << " HP!" << std::endl;
	else
		std::cout << MAX_HP << "(max) HP!" << std::endl;
}