/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:34:14 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/30 15:40:16 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

std::vector<long long>&	jacobsthalNumbers(int n);
long long	nthJacobsNum(int n);


template <typename ContCont, typename Cont>
class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(char** argv);
		PmergeMe(const PmergeMe& other);
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& other);

		void	FordJohnson();

		Cont&	argToCont(int ac, char** av);

		//Jacobsthal numbers
		long long	nthJacobsNum(int n);
		std::vector<long long>&	jacobsthalNumbers(int len);

		class Timer {
			public:
				Timer();
				Timer(const Timer& other);
				~Timer();
				Timer&	operator=(const Timer& other);
		};
};