/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:33:47 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/23 13:34:52 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <string>

class BitcoinExchange {
	private:
		std::map<std::string, float>	exchange_rates_;
		std::map<std::string, float>	values_;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string input);
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange();
		BitcoinExchange&	operator=(const BitcoinExchange& other);

		void	contentParser(std::string);
};