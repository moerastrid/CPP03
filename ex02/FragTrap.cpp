/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/25 18:04:03 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/02 20:04:25 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// P R I V A T E

FragTrap::FragTrap() {
	std::cout << "\033[1;32m" << "FragTrap default constructor called" << "\033[0m" << std::endl;
	this->_name = "default";
	this->_hp = 100;
	this->_energy = 100;
	this->_damage = 30;
}

void	FragTrap::noEnergy() {
	std::cout << "\033[1;31m" << "FragTrap " << _name << " has no energy left!" << "\033[0m" << std::endl;
}

void	FragTrap::noHP() {
	std::cout << "\033[1;31m" << "FragTrap " << _name << " has no HP left!" << "\033[0m" << std::endl;
}

// P U B L I C

FragTrap::FragTrap(std::string name) {
	std::cout << "\033[1;32m" << "FragTrap constructor(name) called, creating: " << name << "\033[0m" << std::endl;
	this->_name = name;
	this->_hp = 100;
	this->_energy = 100;
	this->_damage = 30;
}

FragTrap::~FragTrap() {
	std::cout << "\033[1;31m" << "FragTrap " << this->_name << ": default destructor called" << "\033[0m" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &src)
{
	std::cout << "\033[1;35m" << "FragTrap '=' sign operator called" << "\033[0m" << std::endl;
	this->_name = src._name;
	this->_hp = src._hp;
	this->_energy = src._energy;
	this->_damage = src._damage;
	return (*this);
}

FragTrap::FragTrap(FragTrap const &src) {
	std::cout << "\033[1;35m" << "FragTrap copy constructor called" << "\033[0m" << std::endl;
	*this = src;
}

void	FragTrap::attack(const std::string &target) {
	if (_hp == 0)
		return (noHP());
	if (_energy == 0)
		return (noEnergy());
	_energy--;
	std::cout << "\033[1;36m" << "FragTrap " << _name << " attacks " << target << ", causing ";
	std::cout << _damage << " points of damage!" << "\033[0m" << std::endl;
}

void	FragTrap::takeDamage(int amount) {
	if (_hp == 0)
		return (noHP());
	if (amount < 0)
		return (beRepared(-1 * amount));
	else if ((unsigned int)amount > _hp)
		_hp = 0;
	else
		_hp -= amount;
	std::cout << "\033[1;36m" << "FragTrap " << _name << " takes " << amount;
	std::cout << " damage, it has " << _hp << " HP left!" << "\033[0m" << std::endl;
}

void	FragTrap::beRepared(int amount) {
	if (_hp == 0)
		return (noHP());
	if (amount < 0)
		return (takeDamage(-1 * amount));
	else if (_energy == 0)
		return (noEnergy());
	_energy--;
	_hp += amount;
	std::cout << "\033[1;36m" << "FragTrap " << _name << " repairs itself with " << amount;
	std::cout << ", it now has " << _hp << " HP!" << "\033[0m" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "\033[1;33m" << "FragTrap " << _name << " gives you a high five!" << "\033[0m" << std::endl;
}
