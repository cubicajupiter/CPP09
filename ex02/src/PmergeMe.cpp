/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:34:19 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/28 11:26:23 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<long long>&	jacobsthalNumbers(int n) {
	std::vector<long long>	jnums;
	size_t				i = 2;

	if (n > 0)
		jnums.push_back(0);
	if (n > 1)
		jnums.push_back(1);
	for (size_t i = 2; i < n; ++i) {
		jnums.push_back(jnums[i - 1] + 2 * jnums[i - 2]);
	}
	return jnums;
}

long long	nthJacobsNum(int n) {
	return ((1 << n + 1) + ((n & 1) ? -1 : 1)) / 3;
}

//(https://vivekupadhyay125.wordpress.com/wp-content/uploads/2013/08/donald-e-knuth-the-art-of-computer-programming-vol-3.pdf)
//page 184
void	PmergeMe::fordJohnson() {
	// FordJohnson from the book! 
	// BUT THE BOOK HAD AN EXAMPLE SEQUENCE OF 21 INTEGERS ONLY.
	//	1: split the sequence into pairs
	//		(separate the straggler if odd number of ints)
	//	2: sort the pairs by their larger mate
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