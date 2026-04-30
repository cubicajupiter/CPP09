/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:34:17 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/30 15:40:18 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Ford-Johnson (merge-insertion sort) algorithm
📖 https://en.wikipedia.org/wiki/Merge-insertion_sort
📖 https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91
📖 https://warwick.ac.uk/fac/sci/dcs/teaching/material-archive/cs341/fj.pdf

std::vector and std::deque
📖 https://en.cppreference.com/w/cpp/container/vector
📖 https://en.cppreference.com/w/cpp/container/deque

Binary insertion sort
📖 https://www.geeksforgeeks.org/dsa/binary-insertion-sort/

Jacobsthal numbers
📖 https://en.wikipedia.org/wiki/Jacobsthal_number


std::chrono
📖 https://en.cppreference.com/w/cpp/chrono
*/

#include "PmergeMe.hpp"
#include <chrono>
#include <iostream>
#include <vector>
#include <deque>

int	main(int ac, char** av) {
	if (ac > 1) {
		{
			PmergeMe<std::vector<std::vector<int>>, std::vector<int>>		sorter;
			
			try {
				sorter.argToCont(ac, av);
			} catch (std::exception& e) {
				std::cout << e.what();
				return 1;
			}
		
			const auto	start = std::chrono::steady_clock::now(); //put chronos into Time inside sorter methods.
			sorter.FordJohnson();
			const auto	end = std::chrono::steady_clock::now(); //put chrono end into Time destructor inside sorter methods.
			const auto	duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); //put chronos into Time class

			//std::cout << duration << "\n";	//printworks here
		}
		{
			std::deque<int>		input_sequence;

			try {
				input_sequence = PmergeMe::argToDeq(ac, av);
			} catch (std::exception& e) {
				std::cout << e.what();
				return 1;
			}

			const auto	start = std::chrono::steady_clock::now();
			PmergeMe::dequeFordJohnson(input_sequence);
			const auto	end = std::chrono::steady_clock::now();
			const auto	duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

			//std::cout << duration << "\n";	//printworks here
		}
	}
	else {
		std::cout << "\nUsage: ./PmergeMe <sequence of positive integers>\nFor example: `./PmergeMe 5 4 87 12 2 50`\n\n";
	}
	return 0;
}