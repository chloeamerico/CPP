/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:39:30 by camerico          #+#    #+#             */
/*   Updated: 2025/12/03 17:30:02 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    ClapTrap CC("CP01");        //on cree un object de la classe ClapTrack

    std::cout << "CC's energy points before attack : " << CC.get_energy() << std::endl;
    CC.attack("ennemy");        //on test l'attaque sur "ennemy"
    std::cout << "CC's energy points after attack: " << CC.get_energy() << std::endl << std::endl;
    

    std::cout << "CC's life points before takeDamage: " << CC.get_lifepoints() << std::endl;
    CC.takeDamage(3);
    std::cout << "CC's life points after takeDamage: " << CC. get_lifepoints() << std::endl << std::endl;

    
    std::cout << "CC's life points before beRepeared: " << CC.get_lifepoints() << std::endl;
    std::cout << "CC's energy points before beRepeared: " << CC.get_energy() << std::endl;
    CC.beRepaired(2);
    std::cout << "CC's life points after takeDamage: " << CC. get_lifepoints() << std::endl;
    std::cout << "CC's energy points after beRepeared: " << CC.get_energy() << std::endl << std::endl;

    
    std::cout << "CC's life points before takeDamage: " << CC.get_lifepoints() << std::endl;
    CC.takeDamage(10);
    std::cout << "CC's life points after takeDamage: " << CC. get_lifepoints() << std::endl << std::endl;
    

    std::cout << "CC's life points before beRepeared: " << CC.get_lifepoints() << std::endl;
    std::cout << "CC's energy points before beRepeared: " << CC.get_energy() << std::endl;
    CC.beRepaired(2);
    std::cout << "CC's life points after takeDamage: " << CC. get_lifepoints() << std::endl;
    std::cout << "CC's energy points after beRepeared: " << CC.get_energy() << std::endl << std::endl;

}