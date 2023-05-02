/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: astrid <astrid@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 14:13:24 by astrid        #+#    #+#                 */
/*   Updated: 2023/05/02 15:44:54 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
    std::cout << "FragTrap default constructor called" << std::endl;
    this->_name = "default";
    this->_hp = 100;
    this->_energy = 100;
    this->_damage = 30;
}

// // P U B L I C

FragTrap::FragTrap(std::string name) {
    std::cout << "\033[1;32m" << "FragTrap constructor(name) called, creating: " << name << "\033[0m" << std::endl;
    this->_name = name;
    this->_hp = 100;
    this->_energy = 100;
    this->_damage = 30;
}

FragTrap::FragTrap(std::string *name) {
    std::cout << "\033[1;32m" << "FragTrap constructor(*name) called" << "\033[0m" << std::endl;
    if (name == NULL)
        this->_name = "NULL";
    this->_hp = 100;
    this->_energy = 100;
    this->_damage = 30;
}

FragTrap::~FragTrap() {
	std::cout << "\033[1;31m" << "FragTrap " << this->_name << ": default destructor called" << "\033[0m" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &src) {
    std::cout << "\033[1;34m" << "FragTrap '=' sign operator called" << "\033[0m" << std::endl;
	this->_name = src._name;
	this->_hp = src._hp;
	this->_energy = src._energy;
	this->_damage = src._damage;
	return (*this);
}

FragTrap::FragTrap(FragTrap const &src) {
    std::cout << "\033[1;34m" << "FragTrap copy constructor called" << "\033[0m" << std::endl;
    *this = src;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "\033[1;33m" << "FragTrap " << this->_name << " gives you a high five!" << "\033[0m" << std::endl;
}


void	FragTrap::attack(const std::string &target) {
	if (this->_hp == 0)
		return (this->noHP());
	if (this->_energy-- == 0)
		return (this->noEnergy());
	std::cout << "\033[1;35m" << "FragTrap " << this->_name << " attacks " << target << ", causing ";
	std::cout << this->_damage << " points of damage!" << "\033[0m" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount) {
	if (this->_hp == 0)
		return (this->noHP());
	this->_hp -= amount;
	if (this->_hp < 0)
		this->_hp = 0;
	std::cout << "\033[1;36m" << "FragTrap " << this->_name << " takes " << amount;
	std::cout << " damage, it has " << this->_hp << " HP left!" << "\033[0m" << std::endl;
}

void	FragTrap::beRepared(unsigned int amount) {
	if (this->_hp == 0)
		return (this->noHP());
	if (this->_energy-- == 0)
		return (this->noEnergy());
	this->_hp += amount;
	if (this->_hp > MAX_HP)
		this->_hp = MAX_HP;
	std::cout << "\033[1;30m" << "FragTrap " << this->_name << " repairs itself with " << amount << ", it now has ";
	if (this->_hp != MAX_HP)
		std::cout << this->_hp << " HP!" << "\033[0m" << std::endl;
	else
		std::cout << MAX_HP << "(max) HP!" << "\033[0m" << std::endl;
}