/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:34:17 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/28 11:26:25 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Ford-Johnson (merge-insertion sort) algorithm
📖 https://en.wikipedia.org/wiki/Merge-insertion_sort
📖 Helpful community breakdown: https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort


std::vector and std::deque
📖 https://en.cppreference.com/w/cpp/container/vector
📖 https://en.cppreference.com/w/cpp/container/deque


Jacobsthal numbers
📖 https://en.wikipedia.org/wiki/Jacobsthal_number


std::chrono
📖 https://en.cppreference.com/w/cpp/chrono
*/

#include "PmergeMe.hpp"
#include <chrono>
#include <iostream>

int	main(int ac, char** av) {
	if (ac > 1) {
		const auto	start = std::chrono::steady_clock::now();
		
		PmergeMe::fordJohnson();

		const auto	end = std::chrono::steady_clock::now();
		const auto	duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	}
	return 0;
}