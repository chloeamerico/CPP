/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:04:54 by camerico          #+#    #+#             */
/*   Updated: 2025/10/27 19:32:10 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Implémentation de la classe PhoneBook
// ne peut contenir que 8 contacts max, si on y ajoute un 9eme, il remplace le plsu ancien
//doit gerer : ADD, SEARCH et EXIT

#include "PhoneBook.hpp"


PhoneBook::PhoneBook() : _nb_contacts(0), _current_contact(0) {}



