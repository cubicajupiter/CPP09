/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:34:19 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/29 16:24:05 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <charconv>
#include <deque>
#include <vector>

std::vector<long long>&	jacobsthalNumbers(int len) {
	std::vector<long long>	jnums;
	size_t	i = 2;

	if (len > 0)
		jnums.push_back(0);
	if (len > 1)
		jnums.push_back(1);
	for (size_t i = 2; i < len; ++i) {
		jnums.push_back(jnums[i - 1] + 2 * jnums[i - 2]);
	}
	return jnums;
}

long long	nthJacobsNum(int n) {
	return ((1 << n + 1) + ((n & 1) ? -1 : 1)) / 3;
}

std::vector<int>&	PmergeMe::argToVec(int ac, char** av) {
	std::vector<int>		input;
	std::from_chars_result	res;
	int		value;

	for (size_t i = 0; av[i] != nullptr; ++i) {
		res = std::from_chars(&av[i][0], &av[i][-1], value);	//find a better approach than -1 for back pointer
	}
	return input;
}

std::deque<int>&	PmergeMe::argToDeq(int ac, char** av) {
	std::deque<int>			input;
	std::from_chars_result	res;
	int		value;

	for (size_t i = 0; av[i] != nullptr; ++i) {
		res = std::from_chars(&av[i][0], &av[i][-1], value);	//find a better approach than -1 for back pointer
	}
	return input;
}

//(https://vivekupadhyay125.wordpress.com/wp-content/uploads/2013/08/donald-e-knuth-the-art-of-computer-programming-vol-3.pdf)
//page 184
void	PmergeMe::vectorFordJohnson() {
	// FordJohnson from the book!
	// BUT THE BOOK HAD AN EXAMPLE SEQUENCE OF 21 INTEGERS ONLY.
	//	1: split the sequence into pairs
	//		(separate the straggler if odd number of ints)
			//recursively keep splitting into larger and larger pairs
			//note the loser in a list with the winner.
	//	2: sort the pairs by their larger mate
			//recursively keep splitting into larger and larger pairs	recursive pairing of pairs happens before, _during_ or after sorting??
			//note the loser in a list with the winner.
	//	3: Insert the first set of lower mates: b2(below a2) and b3(below a3)
	//		b's are always the smaller of the mates: inserted lower than their mate.
	//	4: Insert b5 using THREE comparisons (binary sort: c4 then c2 then c6)
	//		Then insert b4 in THREE more comparisons.
	//	5: Insert STRAGGLER using FOUR comparisons.
	//		(binary sort into a main-chain of 10 elements)
	//	6: Insert in descending order the rest of the b's,
	//		starting from the mate of the biggest a!
	;
}

void	PmergeMe::dequeFordJohnson() {
	;
}

//binary search
//std::upper_bound