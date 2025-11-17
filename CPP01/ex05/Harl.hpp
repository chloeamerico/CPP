/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:26:20 by camerico          #+#    #+#             */
/*   Updated: 2025/11/17 16:09:11 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {

	private :

	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	
	public :
	Harl();
	~Harl();

	void complain( std::string level );
};


#endif