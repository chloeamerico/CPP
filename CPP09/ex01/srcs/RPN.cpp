/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:46:23 by camerico          #+#    #+#             */
/*   Updated: 2026/02/20 18:10:26 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& copy) : _pile(copy._pile) {}

RPN& RPN::operator=(const RPN& copy)
{
	if(this != &copy)
	{
		_pile = copy._pile;
	}
	return *this;
}

RPN::~RPN() {}


//METHODS


static bool is_number(std::string &s)
{
	if(s.size() == 1 && isdigit(s[0]))
		return true;
	else
		return false;
}

static bool is_sign(std::string &s)
{
	if (s.size() == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/'))
		return true;
	else
		return false;
}

static double calcul(double a, double b, char op)
{
	if(op == '+')
		return a + b;
	
	if(op == '-')
		return a - b;

	if (op == '*')
		return a * b;

	if (op == '/')
	{
		if (b == 0.0)
			throw std::runtime_error("Error");
		else
			return a / b;
	}
	else
		return 1;
}


//top() pour voir le premier element de la pile
//pop() pour supp le premier element de la pile
void RPN::run(const std::string &str)
{	
	std::istringstream iss(str);
	std::string token;

	while(iss >> token)
	{
		
		if(token.size() != 1 || (!is_number(token) && !is_sign(token)))
			throw std::runtime_error("Error");

		if(is_number(token))
		{
			_pile.push(static_cast<double>(token[0] - '0'));
		}
		
		else //calcul
		{
			if(_pile.size() < 2)
				throw std::runtime_error("Error");

			double a = _pile.top();
			_pile.pop();
			double b = _pile.top();
			_pile.pop();

			double result = calcul(b, a, token[0]);
			_pile.push(result);
		}
	}
	if(_pile.size() != 1)
		throw std::runtime_error("Error");
}

double RPN::get_result() const
{
	return _pile.top();
}

