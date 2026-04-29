/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:34:14 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/29 16:24:12 by jvalkama         ###   ########.fr       */
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
		void				vectorFordJohnson();
		void				dequeFordJohnson();
		std::vector<int>&	argToVec(int ac, char** av);
		std::deque<int>&	argToDeq(int ac, char** av);
};