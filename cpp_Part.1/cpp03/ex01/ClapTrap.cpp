/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:25:54 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/19 12:05:22 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : _name(name), _health(10), _energy(10), _attack(0)
{
    std::cout << GRN "ClapTrap Constructor called for " << this->_name << RST << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << RED "~ClapTrap Destructor called for " << this->_name << "~" RST<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
    : _name(src._name), _health(src._health), _energy(src._energy), _attack(src._attack)
{
    std::cout << GRN "ClapTrap Copy constructor called" RST<< std::endl;
}


ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
    std::cout << "ClapTrap Assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_health = rhs._health;
        this->_energy = rhs._energy;
        this->_attack = rhs._attack;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_health <= 0)
    {
        std::cout << RED "ClapTrap " << this->_name << " cannot attack, he's DEAD :( \"R.I.P.\"" RST << std::endl;
        return;
    }
    else if (this->_energy <= 0)
    {
        std::cout << MAG "ClapTrap " << this->_name << " cannot attack, he's out of energy :/" RST << std::endl;
        return;
    }
    std::cout << BLU "ClapTrap " << this->_name << " attacks " 
        << target << ", causing " << this->_attack << " points of damage!" RST << std::endl;
    this->_energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_health <= 0)
    {
        std::cout << RED "ClapTrap " << this->_name << " cannot take damage, he's DEAD :( \"R.I.P.\"" RST << std::endl;
        return;
    }
    std::cout << YEL "ClapTrap " << this->_name << " takes " << amount << " points of damage!" RST << std::endl;
    if (this->_health < amount)
        this->_health = 0;
    else
        this->_health -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_health <= 0)
    {
        std::cout << RED "ClapTrap " << this->_name << " cannot be repaired, he's DEAD :( \"R.I.P.\"" RST << std::endl;
        return;
    }
    else if (this->_energy <= 0)
    {
        std::cout << MAG "ClapTrap " << this->_name << " cannot be repaired, he's out of energy :/" RST << std::endl;
        return;
    }
    std::cout << YEL "ClapTrap " << this->_name << " is repaired for " << amount << " points of health!" RST<< std::endl;
    this->_health += amount;
}

// Getter pour _name
std::string ClapTrap::getName(void) const
{
    return _name;
}

// Getter pour _health
unsigned int ClapTrap::getHealth(void) const
{
    return _health;
}

// Getter pour _energy
unsigned int ClapTrap::getEnergy(void) const
{
    return _energy;
}

// Getter pour _attack
unsigned int ClapTrap::getAttack(void) const
{
    return _attack;
}

// Setter pour _health
void ClapTrap::setHealth(unsigned int health)
{
    _health = health;
}

// Setter pour _energy
void ClapTrap::setEnergy(unsigned int energy)
{
    _energy = energy;
}

// Setter pour _attack
void ClapTrap::setAttack(unsigned int attack)
{
    _attack = attack;
}
