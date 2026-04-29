/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:34:07 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/26 13:41:53 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Ex01: Reverse Polish Notation
Core concepts:

std::stack — the natural container for RPN evaluation

📖 https://en.cppreference.com/w/cpp/container/stack


std::istringstream — tokenizing the argument string

📖 https://en.cppreference.com/w/cpp/io/basic_istringstream


Exception handling (try / catch / throw) for error output to std::cerr

📖 https://en.cppreference.com/w/cpp/language/exceptions

*/

#include "RPN.hpp"
#include <iostream>

int	main(int ac, char** av) {
	if (ac == 2) {
		try {
			std::cout << RPN::evaluate(av[1]) << "\n";
		} catch (std::exception& e) {
			std::cout << e.what();
		}
	}
	else {
		std::cout << "\nUsage: ./RPN \"<mathematical expression>\"\n\n";
	}
	std::cout << std::flush;
	return 0;
}