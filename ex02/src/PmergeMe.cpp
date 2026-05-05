/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:34:19 by jvalkama          #+#    #+#             */
/*   Updated: 2026/05/05 16:22:20 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <charconv>
#include <deque>
#include <vector>
#include <cstring>
#include <stdexcept>

//ORTHODOX CANONICAL CLASS FORM--------------------
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char** argv) {}

PmergeMe::PmergeMe(const PmergeMe& other) {}

PmergeMe::~PmergeMe() {}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other) {}
//-------------------------------------------------


//JACOBSTHAL METHODS---------------------------------------------
std::vector<long long>&	PmergeMe::JacobsthalNumbers(int len) {
	std::vector<long long>	jnums;
	size_t	i = 2;

	if (len > 0)
		jnums.push_back(0);
	if (len > 1)
		jnums.push_back(1);
	for (size_t i = 2; i < len; ++i) {
		jnums.push_back(jnums[i - 1] + 2 * jnums[i - 2]);
	}
	return jnums;
}

long long	PmergeMe::nthJacobsNum(int n) {
	return ((1 << n + 1) + ((n & 1) ? -1 : 1)) / 3;
}
//---------------------------------------------------------------


//FORDJOHNSON------------------------------------------------------------------------
void	PmergeMe::FordJohnson(ContV& sequence) {
	this->depth_lvl_ = 0;

	//LAUNCH RECURSION
	//START TIMER
	rSort(sequence);
	//END TIMER

}

void	PmergeMe::FordJohnson(ContD& sequence) {
	this->depth_lvl_ = 0;

	//LAUNCH RECURSION
	//START TIMER
	rSort(sequence);
	//END TIMER
	
}

void	PmergeMe::rSort(ContV& sequence) {
		
	//UP-RECURSION:
	//DEPTH OF RECURSION: RETURN BACK TO prev recursion level IF CANNOT FORM TWO PAIRS
	int element_length = 1 << depth_lvl_;
	int element_count = sequence.size() / element_length;
	if (element_count == 1)
		return ;
	PairSwap(sequence);

	rSort(sequence);
	//EACH RETURN-RECURSION LEVEL DOES THE FOLLOWING:
	
	//DOWN-RECURSION:
	//STEP 2:--------------------------------------------------------------------------------------------
	//CREATE MAIN CHAIN:
 	ContContV	main_chain;
	ContContV	pend;
	ContV		bounds;
	MainPendFill(main_chain, pend, bounds);
	//----------------------------------------------------------------------------------------------------

	//STEP 3:---------------------------------------------------------------------------------------------
	//BINARY INSERTION SORT - insert next set of B values from pend to sorted mainchain
	//Into subarray of mainchain indexed into by jacobsthal numbers
	BinaryInsertion(sequence, main_chain, pend, bounds);

}

void	PmergeMe::rSort(ContD& sequence) {

	//UP-RECURSION:
	//DEPTH OF RECURSION: RETURN BACK TO prev recursion level IF CANNOT FORM TWO PAIRS
	int element_length = 1 << depth_lvl_;
	int element_count = sequence.size() / element_length;
	if (element_count == 1)
		return ;
	PairSwap(sequence);

	rSort(sequence);


	//EACH RETURN-RECURSION LEVEL DOES THE FOLLOWING:

	//DOWN-RECURSION:
	//STEP 2:--------------------------------------------------------------------------------------------
	//CREATE MAIN CHAIN AND PEND:
	//	you perform sort and insertion on the original sequence.
	//	main chain and pend are only temporary per each level.
	//	bounds tracks the index of A values inside the evolving sequence
 	ContContD	main_chain;
	ContContD	pend;
	ContD		bounds;
	MainPendFill(main_chain, pend, bounds);
	//----------------------------------------------------------------------------------------------------

	//STEP 3:---------------------------------------------------------------------------------------------
	//BINARY INSERTION SORT - insert next set of B values from pend to sorted mainchain
	//Into subarray of mainchain indexed into by jacobsthal numbers
	BinaryInsertion(sequence, main_chain, pend, bounds);

}

//binary insertion needs to happen in recursivePairing
//since we need to be at the max depth of recursion when binary insertion begins
void	PmergeMe::PairSwap(ContV& sequence) {
	ContContV	new_element;
	ContV		non_participating;

	//STEP 1: PAIRING-----------------------------------------------------------------------------------
	//level 0: create pairs of integers
	//level 1: create pairs of vectors of integers (put in a vector BOTH OR ALL ints of previous pair)

	//YOU ONLY EVER HAVE A VECTOR OF VECTORS OF INTS: move items from previous ContCont to new
	//"concatenating" two element containers to form the next level: ALGORITHMINC INSTEAD VS MANUAL LOOPING
	//MANUAL LOOP APPENDING:
	for (int i = 0; ; ++i) {
		for (int j = 0; j < element_length; ++j) {
			new_element[j] = 
		}
	}
	//ALGORITHMIC APPENDING:
	vector1.insert( vector1.end(), vector2.begin(), vector2.end() );

	depth_lvl_++;
	std::swap();



}

void	PmergeMe::PairSwap(ContD& input_sequence) {
	//prolly just copy paste most of vector pairSwap.
}

void	PmergeMe::MainPendFill(ContContV& main_chain, ContContV& pend, ContV& bounds) {

}

void	PmergeMe::MainPendFill(ContContD& main_chain, ContContD& pend, ContD& bounds) {

}

void	PmergeMe::BinaryInsertion(ContV& sequence, ContContV& main_chain, ContContV& pend, ContV& bounds) {
	auto insertB = std::upper_bound(mainChain.jacobIter, mainChain.jacobIterEnd, value);	//value is the insert condition: first element larger than value
	if (insertB != mainChain.jacobIterEnd) {
		//insert in `insertB - 1`: one before the returned (larger) element
	}
}

void	PmergeMe::BinaryInsertion(ContD& sequence, ContContD& main_chain, ContContD& pend, ContD& bounds) {
	auto insertB = std::upper_bound(mainChain.jacobIter, mainChain.jacobIterEnd, value);	//value is the insert condition: first element larger than value
	if (insertB != mainChain.jacobIterEnd) {
		//insert in `insertB - 1`: one before the returned (larger) element
	}
}