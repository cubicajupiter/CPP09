/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:34:09 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/26 13:57:26 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <regex>

int	RPN::evaluate(std::string_view rpn) {
	if (inputValidation(rpn) == false) {
		throw std::invalid_argument("\nError: Faulty RPN format passed as argument!\n\n");
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
	size_t		size;
	int			result;
	int			top;

	size = rpn.size();
	for (size_t i = 0; i < size; ++i) {
		switch (rpn[i]) {
			case ' ': case '\t': case '\n': case '\r': case '\f': case '\v':
				break;
			case '+':	
				top = operands_.top();
				operands_.pop();
				operands_.top() += top;
				break;
			case '-':
				top = operands_.top();
				operands_.pop();
				operands_.top() -= top;
				break;
			case '*':
				top = operands_.top();
				operands_.pop();
				operands_.top() *= top;
				break;
			case '/':
				top = operands_.top();
				operands_.pop();
				operands_.top() /= top;
				break;
			default:
				operands_.push(rpn[i] - '0');
				break;
		}
	}
	if (operands_.size() != 1) {
		operands_ = std::stack<int>();
		throw std::invalid_argument("\nError: Faulty RPN format passed as argument!\n"
			"Only numbers between 0 to 9, and the operators + - * / are allowed.\n\n");
	}
	result = operands_.top();
	operands_.pop();
	return result;
}