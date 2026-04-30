/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:34:19 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/30 15:40:14 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <charconv>
#include <deque>
#include <vector>
#include <cstring>

//ORTHODOX CANONICAL CLASS FORM--------------------
template <typename ContCont, typename Cont>
PmergeMe<ContCont, Cont>::PmergeMe() {}

template <typename ContCont, typename Cont>
PmergeMe<ContCont, Cont>::PmergeMe(char** argv) {}

template <typename ContCont, typename Cont>
PmergeMe<ContCont, Cont>::PmergeMe(const PmergeMe& other) {}

template <typename ContCont, typename Cont>
PmergeMe<ContCont, Cont>::~PmergeMe() {}

template <typename ContCont, typename Cont>
PmergeMe<ContCont, Cont>&	PmergeMe<ContCont, Cont>::operator=(const PmergeMe& other) {}
//-------------------------------------------------


//JACOBSTHAL METHODS---------------------------------------------
template <typename ContCont, typename Cont>
std::vector<long long>&	PmergeMe<ContCont, Cont>::jacobsthalNumbers(int len) {
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

template <typename ContCont, typename Cont>
long long	PmergeMe<ContCont, Cont>::nthJacobsNum(int n) {
	return ((1 << n + 1) + ((n & 1) ? -1 : 1)) / 3;
}
//---------------------------------------------------------------


//PARSER--------------------------------------------------------------------
template <typename ContCont, typename Cont>
Cont&	PmergeMe<ContCont, Cont>::argToCont(int ac, char** av) {
	Cont			input;
	int				value{};
	std::size_t		back;

	for (std::size_t i = 0; av[i] != nullptr; ++i) {
		back = std::strlen(av[i]) - 1;
		auto [ptr, ec] = std::from_chars(&av[i][0], back, value);
		if (*ptr != '\0')
			throw std::invalid_argument("Error: invalid char after number.\n");
		if (ec == std::errc::invalid_argument)
			throw std::invalid_argument("Error: non-number argument.\n");
		if (ec == std::errc::result_out_of_range)
			throw std::invalid_argument("Error: number larger than an int.\n");
		if (ec != std::errc())
			throw std::invalid_argument("Error!");
		input.push_back(value);
	}
	return input;
}
//---------------------------------------------------------------------------

//(https://vivekupadhyay125.wordpress.com/wp-content/uploads/2013/08/donald-e-knuth-the-art-of-computer-programming-vol-3.pdf)
//page 184
template <typename ContCont, typename Cont>
void	PmergeMe<ContCont, Cont>::FordJohnson() {
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

//binary search
//std::upper_bound