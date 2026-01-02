/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:09:00 by camerico          #+#    #+#             */
/*   Updated: 2026/01/02 16:49:51 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base() {}


//instancie aleatoirement A, B ou C
Base* generate(void)
{
	//a initialiser 1 seule fois : donc dans le main
	//srand(time(NULL));
	int random = rand() % 3;
	
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

// affiche le type via pointeur
//pour check le type reel du pointeur, utiliser dynamic_cast
void identify(Base* p)
{
	if(dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "the type is : A" << std::endl;
		return;
	}
	if(dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "the type is : B" << std::endl;
		return;
	}
	if(dynamic_cast<C*>(p) != NULL)
	{
		std::cout << "the type is : C" << std::endl;
		return;
	}
}

//affiche le type par reference
//toujorus avec dynamic cast, mais on utilise un try/catch car si le cast avec une reference echoue, lamce exception, 
void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "the type is : A" << std::endl;
		return;
	}
	catch(std::bad_cast&)
	{}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "the type is : B" << std::endl;
		return;
	}
	catch(std::bad_cast&)
	{}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "the type is : C" << std::endl;
		return;
	}
	catch(std::bad_cast&)
	{}
}