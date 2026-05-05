/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:34:14 by jvalkama          #+#    #+#             */
/*   Updated: 2026/05/05 16:18:15 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

std::vector<long long>&	jacobsthalNumbers(int n);
long long	nthJacobsNum(int n);


class PmergeMe {
		int		depth_lvl_;
	public:
		using ContContV	= std::vector<std::vector<int>>;
		using ContV		= std::vector<int>;
		using ContContD	= std::deque<std::deque<int>>;
		using ContD		= std::deque<int>;


		PmergeMe();
		PmergeMe(char** argv);
		PmergeMe(const PmergeMe& other);
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& other);

		void	FordJohnson(ContV& sequence);
		void	FordJohnson(ContD& sequence);
		void	PairSwap(ContV& sequence);
		void	PairSwap(ContD& sequence);
		void	rSort(ContV& sequence);
		void	rSort(ContD& sequence);
		void	MainPendFill(ContContV& main_chain, ContContV& pend, ContV& bounds);
		void	MainPendFill(ContContD& main_chain, ContContD& pend, ContD& bounds);
		void	BinaryInsertion(ContContV& main_chain, ContContV& pend, ContV& bounds);
		void	BinaryInsertion(ContContD& main_chain, ContContD& pend, ContD& bounds);
	


		//Jacobsthal numbers
		long long	nthJacobsNum(int n);
		std::vector<long long>&	JacobsthalNumbers(int len);

		class Timer {
			public:
				Timer();
				Timer(const Timer& other);
				~Timer();
				Timer&	operator=(const Timer& other);
		};

		//PARSER--------------------------------------------------------------------
		template <typename Cont>
		Cont&	PmergeMe::argToCont(int ac, char** av) {
			char*			arg;
			Cont			input;
			int				value{};
			std::size_t		back;

			for (std::size_t i = 0; av[i] != nullptr; ++i) {
				arg = av[i];
				back = std::strlen(arg) - 1;
				auto [ptr, ec] = std::from_chars(&arg[0], &arg[back], value);
				if (*ptr != '\0')
					throw std::invalid_argument("Error: invalid char after number at arg index " + std::to_string(i) + "\n");
				if (ec == std::errc::invalid_argument)
					throw std::invalid_argument("Error: non-number argument at arg index " + std::to_string(i) + "\n");
				if (ec == std::errc::result_out_of_range)
					throw std::invalid_argument("Error: number is larger than an int at arg index " + std::to_string(i) + "\n");
				if (ec != std::errc())
					throw std::invalid_argument("Error!\n");
				input.push_back(value);
			}
			return input;
		}
		//---------------------------------------------------------------------------
};