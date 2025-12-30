/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:26:36 by camerico          #+#    #+#             */
/*   Updated: 2025/12/30 19:46:17 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/Serializer.hpp"

/* reinterpret_cast :
	- adapté pour les conversions de bas niveau entre pointeurs et entiers
	- il réinterprète directement les bits sans vérification de type
*/

/*reinterpret_cast réinterprète  ici les bits du pointeur comme un entier non signé.*/
//prend un pointeur et le converti vers un unsigned int
uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

/*reinterpret_cast réinterprète  ici le nombre comme un pointeur.*/
//prend un unsigned int et le converti vers un pointeur data
Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}