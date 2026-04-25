/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:34:09 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/25 17:01:24 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <regex>

int	RPN::evaluate(std::string_view rpn) {
	if (inputValidation(rpn) == false) {
		throw std::invalid_argument("Faulty RPN format passed as argument!\n");
	}
	return tokenEvaluation(rpn);
}

bool	RPN::inputValidation(std::string_view rpn) {
	std::regex		pattern(R"(^\s*(?:\d+\s+){2,}(?:(?:\d+|[+\-*/])\s+)*[+\-*/]\s*$)");

	if (std::regex_match(rpn.begin(), rpn.end(), pattern)) {
		return true;
	}
	return false;
}

int	RPN::tokenEvaluation(std::string_view rpn) {
	size_t	size;

	size = rpn.size();
	for (size_t i = 0; i < size; ++i) {
		switch (rpn[i]) {
			case ' ': case '\t': case '\n': case '\r': case '\f': case '\v':
				break;
			case '+':
				//top OR pop values  and push result
				break;
			case '-':
				//top is subtracted from the one below,  and push result
				break;
			case '*':
				//top OR pop values  and push result
				break;
			case '/':
				//top is the divider, below is dividend.  and push result
				break;
			default:
				operands_.push(rpn[i]);
				break;
		}
	}
	// erase/zero-out stack.
	
	// and return value directly
}