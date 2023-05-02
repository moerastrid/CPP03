/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 15:35:53 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/02 19:48:07 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// P R O T E C T E D
ClapTrap::ClapTrap() : _name("default"), _hp(10), _energy(10), _damage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

void	ClapTrap::noEnergy() {
	std::cout << "Claptrap " << _name << " has no energy left!" << std::endl;
}

void	ClapTrap::noHP() {
	std::cout << "Claptrap " << _name << " has no HP left!" << std::endl;
}

// P U B L I C
ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _energy(10), _damage(0) {
	std::cout << "ClapTrap constructor(name) called, creating: " << name << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << ": default destructor called" << std::endl;
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

std::string	ClapTrap::getName() {
	return (_name);
}

void	ClapTrap::setName(std::string name) {
	_name = name;
}

int	ClapTrap::getHP() {
	return (_hp);
}

int	ClapTrap::getEnergy() {
	return (_energy);
}

int	ClapTrap::getDamage() {
	return (_damage);
}

void	ClapTrap::attack(const std::string &target) {
	if (_hp == 0)
		return (noHP());
	if (_energy == 0)
		return (noEnergy());
	_energy--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing ";
	std::cout << _damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(int amount) {
	if (_hp == 0)
		return (noHP());
	if (amount < 0)
		return (beRepared(-1 * amount));
	else if ((unsigned int)amount > _hp)
		_hp = 0;
	else
		_hp -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount;
	std::cout << " damage, it has " << _hp << " HP left!" << std::endl;
}

void	ClapTrap::beRepared(int amount) {
	if (_hp == 0)
		return (noHP());
	if (amount < 0)
		return (takeDamage(-1 * amount));
	else if (_energy == 0)
		return (noEnergy());
	_energy--;
	_hp += amount;
	std::cout << "ClapTrap " << _name << " repairs itself with " << amount;
	std::cout << ", it now has " << _hp << " HP!" << std::endl;
}

// O T H E R
std::ostream	&operator<<(std::ostream &o, ClapTrap &ct)
{
	o << ct.getName() << "\tHP:" << ct.getHP() << "\te:" << ct.getEnergy() << "\td:" << ct.getDamage();
	return (o);
}
