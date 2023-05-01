/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: astrid <astrid@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 14:13:24 by astrid        #+#    #+#                 */
/*   Updated: 2023/05/01 14:41:22 by astrid        ########   odam.nl         */
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
