/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:47:12 by camerico          #+#    #+#             */
/*   Updated: 2025/12/17 13:34:37 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"


//MateriaSource = livre de sorts
//Character = personnage qui utilise des sorts
//Cure et Ice = des sorts



//***********Main du sujet***************

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter* me = new Character("me");

// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
	
// 	ICharacter* bob = new Character("bob");
	
// 	me->use(0, *bob);
// 	me->use(1, *bob);
	
// 	delete bob;
// 	delete me;
// 	delete src;
	
// 	return 0;
// }



// /***********main pour test un invotory plein avec  4 slots remplis et le unequip et slot invalid *******/

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* hero = new Character("hero");

	//on cree puis equip les 4 materias
	AMateria* m1 = src->createMateria("ice");
	AMateria* m2 = src->createMateria("cure");
	AMateria* m3 = src->createMateria("ice");
	AMateria* m4 = src->createMateria("cure");

	hero->equip(m1);
	hero->equip(m2);
	hero->equip(m3);
	hero->equip(m4);

	//ne fait rien car l'inventaire est deja plein
	AMateria* m5 = src->createMateria("ice");
	hero->equip(m5);
	delete m5;

	ICharacter* enemy = new Character("enemy");
	
	std::cout << "*****Test avant de unequip *****" << std::endl << std::endl;
	
	hero->use(0, *enemy);		//utilise ice
	hero->use(1, *enemy);		//utilise cure
	hero->use(2, *enemy);		//utilise ice
	hero->use(3, *enemy);		//utilise cure
	

	std::cout << std::endl << "*****Test apres unequip le premier sort *****" << std::endl << std::endl;

	hero->unequip(0);		//retire le premier ice, mais ne le delete pas
	
	hero->use(0, *enemy);		//ne doit rien faire
	hero->use(1, *enemy);		//utilise cure
	hero->use(2, *enemy);		//utilise ice
	hero->use(3, *enemy);		//utilise cure
	hero->use(10, *enemy);		//ne fait rien car le slot n'existe pas 

	delete m1;		//doit le delete manuellement
	delete enemy;
    delete hero;
    delete src;
}
