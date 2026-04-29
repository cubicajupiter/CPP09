/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:33:54 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/23 13:34:53 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Ex00: Bitcoin Exchange
Core concepts:

std::map — storing and querying the CSV database

📖 https://en.cppreference.com/w/cpp/container/map


std::map::lower_bound — finding the closest lower date

📖 https://en.cppreference.com/w/cpp/container/map/lower_bound


File I/O with std::ifstream and line parsing with std::getline / std::istringstream

📖 https://en.cppreference.com/w/cpp/io/basic_ifstream


String-to-number conversion (std::stof, std::stod, or std::strtod for robust error handling)

📖 https://en.cppreference.com/w/cpp/string/basic_string/stof

*/

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

static std::string	fileOperation(char *file_name);
static void			errorExit(std::string msg);

int	main(int ac, char **av) {
	if (ac == 2) {
		std::string		file_rawdata;
		file_rawdata = fileOperation(av[1]);
		
		BitcoinExchange		btc_op(file_rawdata);

	}
	else
		errorExit("Error: No input file argument!\nUsage: ./btc [file name]");
	return 0;
}

static std::string	fileOperation(char *file_name) {
	std::ifstream		instream;
	std::ostringstream  buffer;

	instream.open(file_name);
	if (!instream.is_open()) {
		errorExit("Error: File access failure!");
	}
	buffer << instream.rdbuf();
	if (!buffer) {
		if (errno = 0)
			errorExit("Error: File is empty!");
		errorExit("Error: File access failure!");
	}
	return buffer.str();
}

static void	errorExit(std::string msg) {
	std::cout << msg << std::endl;
	exit(1);
}

/*
C++ PARSING APPROACHES:

	!!!extraction >> from std::istream object!!!
	`file >> buffer;`
	automatically skips leading whitespace AND treats whitespace as delimiter.
	Not great support for custom delimiters.. stops reading at whitespace
	Input formatted according to type of buffer: 
	interprets characters as representations of a type of value: for `int buffer` it extracts integers.

	std::getline & std::stringstream
	supports custom delimiters
	*/
