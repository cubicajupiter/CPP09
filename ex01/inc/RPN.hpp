/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:34:03 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/25 17:01:28 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <string>

class RPN {
	private:
		static std::stack<int>		operands_;

		RPN() = delete;
		RPN(const RPN& other) = delete;
		~RPN() = delete;
		RPN&	operator=(const RPN& other) = delete;
		
		static bool	inputValidation(std::string_view rpn);
		static int	tokenEvaluation(std::string_view rpn);
		
	public:
		static int		evaluate(std::string_view rpn);
};