/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:39:30 by camerico          #+#    #+#             */
/*   Updated: 2025/12/05 18:29:43 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"
#include "../includes/ClapTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"


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
    DiamondTrap DT("DT01");         //on cree un object de la classe DiamondTrap

    std::cout << "DT's energy points before attack : " << DT.get_energy() << std::endl;
    DT.attack("ennemy");
    std::cout << "DT's energy points after attack : " << DT.get_energy() << std::endl;

    std::cout << std::endl;
    DT.highFivesGuys();

    std::cout << std::endl;
    DT.guardGate();
    
    DT.whoAmI();

    DiamondTrap DT2(DT);
    DT2.whoAmI();

    
    // std::cout << std::endl << "FT's energy points before attack : " << FT.get_energy() << std::endl;
    // FT.attack("ennemy");        //on test l'attaque sur "ennemy"
    // std::cout << "FT's energy points after attack: " << FT.get_energy() << std::endl << std::endl;

    // FT.highFivesGuys();             //test highFivesGuys.
    // std::cout << std::endl;

    // std::cout << "FT's life points before taking damage : " << FT.get_lifepoints() << std::endl;
    // FT.takeDamage(5);
    // std::cout << "FT's life points after taking damage : " << FT.get_lifepoints() << std::endl << std::endl;

    
}
