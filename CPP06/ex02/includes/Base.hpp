/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:00:59 by camerico          #+#    #+#             */
/*   Updated: 2025/12/30 20:08:43 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base {
	
	public :
		virtual ~Base();
};

Base * generate(void);		//instancie aleatoirement A, B ou C
void identify(Base* p);		// affiche le type via pointeur
void identify(Base& p);		//affiche le type par reference


#endif