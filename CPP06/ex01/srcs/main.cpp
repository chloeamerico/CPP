/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:42:32 by camerico          #+#    #+#             */
/*   Updated: 2025/12/30 19:49:11 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/Serializer.hpp"

int main(void)
{
	Data data;
	uintptr_t raw = Serializer::serialize(&data);
	Data* ptr = Serializer::deserialize(raw);

	// ptr doit être égal à data
	std::cout << ptr << std::endl;
	std::cout << &data << std::endl;

}