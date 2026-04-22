/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:33:47 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/22 17:22:31 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <string>

class BitcoinExchange {
	private:
		std::map<std::string, float>		exchange_rates;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string input);
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange();
		BitcoinExchange&	operator=(const BitcoinExchange& other);

		void	contentParser(std::string);
};