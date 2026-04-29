/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:34:14 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/28 11:26:24 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

std::vector<long long>&	jacobsthalNumbers(int n);
long long	nthJacobsNum(int n);

class PmergeMe {
	private:
		PmergeMe() = delete;
		PmergeMe() = delete;
		~PmergeMe() = delete;
		PmergeMe&	operator=(const PmergeMe& other) = delete;
	public:
		void	fordJohnson();
};