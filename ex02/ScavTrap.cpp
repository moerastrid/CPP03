/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/25 18:04:03 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/02 19:57:27 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// P R I V A T E

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_name = "default";
	this->_hp = 100;
	this->_energy = 50;
	this->_damage = 20;
}

void	ScavTrap::noEnergy() {
	std::cout << "ScavTrap " << _name << " has no energy left!" << std::endl;
}

void	ScavTrap::noHP() {
	std::cout << "ScavTrap " << _name << " has no HP left!" << std::endl;
}

// P U B L I C

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
	if (_hp == 0)
		return (noHP());
	if (_energy == 0)
		return (noEnergy());
	_energy--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing ";
	std::cout << _damage << " points of damage!" << std::endl;
}

void	ScavTrap::takeDamage(int amount) {
	if (_hp == 0)
		return (noHP());
	if (amount < 0)
		return (beRepared(-1 * amount));
	else if ((unsigned int)amount > _hp)
		_hp = 0;
	else
		_hp -= amount;
	std::cout << "ScavTrap " << _name << " takes " << amount;
	std::cout << " damage, it has " << _hp << " HP left!" << std::endl;
}

void	ScavTrap::beRepared(int amount) {
	if (_hp == 0)
		return (noHP());
	if (amount < 0)
		return (takeDamage(-1 * amount));
	else if (_energy == 0)
		return (noEnergy());
	_energy--;
	_hp += amount;
	std::cout << "ScavTrap " << _name << " repairs itself with " << amount;
	std::cout << ", it now has " << _hp << " HP!" << std::endl;
}
