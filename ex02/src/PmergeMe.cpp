/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:34:19 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/27 18:36:27 by jvalkama         ###   ########.fr       */
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