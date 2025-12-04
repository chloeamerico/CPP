/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:39:30 by camerico          #+#    #+#             */
/*   Updated: 2025/12/04 18:40:07 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"


//getter pour connaitre le nb de points d'energy
int ClapTrap::get_energy(void) const
{
    return this->_energyPoint;
}

//getter pour connaitre le nb de points de vie
int ClapTrap::get_lifepoints(void) const
{
    return this->_hitPoint;
}



int main(void)
{
    ScavTrap ST("ST01");         //on cree un object de la classe ScavTrap

    std::cout << std::endl << "ST's energy points before attack : " << ST.get_energy() << std::endl;
    ST.attack("ennemy");        //on test l'attaque sur "ennemy"
    std::cout << "ST's energy points after attack: " << ST.get_energy() << std::endl << std::endl;

    ST.guardGate();             //test Gate keeper mode.
    std::cout << std::endl;

    ST.takeDamage(5);
    
    
}
