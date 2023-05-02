/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/25 18:04:03 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/02 19:56:33 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// P R I V A T E

ScavTrap::ScavTrap() {
	std::cout << "\033[1;32m" << "ScavTrap default constructor called" << "\033[0m" << std::endl;
	this->_name = "default";
	this->_hp = 100;
	this->_energy = 50;
	this->_damage = 20;
}

void	ScavTrap::noEnergy() {
	std::cout << "\033[1;31m" << "ScavTrap " << _name << " has no energy left!" << "\033[0m" << std::endl;
}

void	ScavTrap::noHP() {
	std::cout << "\033[1;31m" << "ScavTrap " << _name << " has no HP left!" << "\033[0m" << std::endl;
}

// P U B L I C

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
	std::cout << "\033[1;35m" << "ScavTrap '=' sign operator called" << "\033[0m" << std::endl;
	this->_name = src._name;
	this->_hp = src._hp;
	this->_energy = src._energy;
	this->_damage = src._damage;
	return (*this);
}

ScavTrap::ScavTrap(ScavTrap const &src) {
	std::cout << "\033[1;35m" << "ScavTrap copy constructor called" << "\033[0m" << std::endl;
	*this = src;
}

void	ScavTrap::guardGate(void) {
	std::cout << "\033[1;33m" << "ScavTrap " << this->_name << " is now in Gate keeper mode" << "\033[0m" << std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	if (_hp == 0)
		return (noHP());
	if (_energy == 0)
		return (noEnergy());
	_energy--;
	std::cout << "\033[1;36m" << "ScavTrap " << _name << " attacks " << target << ", causing ";
	std::cout << _damage << " points of damage!" << "\033[0m" << std::endl;
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
	std::cout << "\033[1;36m" << "ScavTrap " << _name << " takes " << amount;
	std::cout << " damage, it has " << _hp << " HP left!" << "\033[0m" << std::endl;
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
	std::cout << "\033[1;36m" << "ScavTrap " << _name << " repairs itself with " << amount;
	std::cout << ", it now has " << _hp << " HP!" << "\033[0m" << std::endl;
}
