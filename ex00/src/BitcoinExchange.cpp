/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:33:51 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/23 13:34:51 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static std::map<std::string, float>		contentParser(std::string filename);

//DEFAULT CONSTRUCTOR
BitcoinExchange::BitcoinExchange() : values_(), exchange_rates_(contentParser("data.csv")) {}

//PARAMETER CONSTRUCTOR
BitcoinExchange::BitcoinExchange(std::string input) : exchange_rates_(contentParser("data.csv")) {}

//COPY CONSTRUCTOR
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)  : exchange_rates_(contentParser("data.csv")) {}

//DESTRUCTOR
BitcoinExchange::~BitcoinExchange() {}

//ASSIGNMENT OPERATOR OVERLOAD
BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other) {}





static std::map<std::string, float>		contentParser(std::string filename) {
	;
}