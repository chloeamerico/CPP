/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 20:46:41 by camerico          #+#    #+#             */
/*   Updated: 2025/12/15 21:01:02 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public :
		Cure();
		Cure(const Cure& copy);
		Cure& operator=(const Cure& copy);
		virtual ~Cure();

	//fonctions membres heritees de AMateria (a redefinir)
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
