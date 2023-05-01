/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 15:35:53 by ageels        #+#    #+#                 */
/*   Updated: 2023/04/25 20:58:27 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// P R I V A T E
ClapTrap::ClapTrap() {
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->_name = "default";
	this->_hp = 10;
	this->_energy = 10;
	this->_damage = 0;
}

ClapTrap::ClapTrap(std::string *name)
{
	std::cout << "ClapTrap constructor(*name) called" << std::endl;
	if (name == NULL)
		this->_name = "NULL";
	this->_hp = 10;
	this->_energy = 10;
	this->_damage = 0;
}

// P U B L I C
ClapTrap::ClapTrap(std::string name) {
	std::cout << "ClapTrap constructor(name) called, creating: " << name << std::endl;
	this->_name = name;
	this->_hp = 10;
	this->_energy = 10;
	this->_damage = 0;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->_name << ": default destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &src)
{
	std::cout << "ClapTrap '=' sign operator called" << std::endl;
	this->_name = src._name;
	this->_hp = src._hp;
	this->_energy = src._energy;
	this->_damage = src._damage;
	return (*this);
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

std::string	ClapTrap::getName(void) {
	std::string temp = this->_name;
	return (temp);
}

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}

long unsigned int	ClapTrap::getHP(void) {
	return (this->_hp);
}

long unsigned int	ClapTrap::getEnergy(void) {
	return (this->_energy);
}

long unsigned int	ClapTrap::getDamage(void) {
	return (this->_damage);
}

void	ClapTrap::noEnergy(void) {
	std::cout << "Claptrap " << this->_name << " has no energy left!" << std::endl;
}

void	ClapTrap::noHP(void) {
	std::cout << "Claptrap " << this->_name << " has no HP left!" << std::endl;
}

void	ClapTrap::attack(const std::string &target) {
	if (this->_hp == 0)
		return (this->noHP());
	if (this->_energy-- == 0)
		return (this->noEnergy());
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing ";
	std::cout << this->_damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hp == 0)
		return (this->noHP());
	this->_hp -= amount;
	if (this->_hp < 0)
		this->_hp = 0;
	std::cout << "ClapTrap " << this->_name << " takes " << amount;
	std::cout << " damage, it has " << this->_hp << " HP left!" << std::endl;
}

void	ClapTrap::beRepared(unsigned int amount) {
	if (this->_hp == 0)
		return (this->noHP());
	if (this->_energy-- == 0)
		return (this->noEnergy());
	this->_hp += amount;
	if (this->_hp > MAX_HP)
		this->_hp = MAX_HP;
	std::cout << "ClapTrap " << this->_name << " repairs itself with " << amount << ", it now has ";
	if (this->_hp != MAX_HP)
		std::cout << this->_hp << " HP!" << std::endl;
	else
		std::cout << MAX_HP << "(max) HP!" << std::endl;
}

// O T H E R
std::ostream	&operator<<(std::ostream &o, ClapTrap &ct)
{
	o << ct.getName() << "\tHP:" << ct.getHP() << "\te:" << ct.getEnergy() << "\td:" << ct.getDamage();
	return (o);
}
