/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:24:16 by camerico          #+#    #+#             */
/*   Updated: 2026/02/20 17:56:00 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/RPN.hpp"

int main (int argc, char **argv)
{
	if(argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try
	{
		RPN rpn;
		rpn.run(argv[1]);
		std::cout << rpn.get_result() << std::endl;
		return 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}