/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:18:49 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/18 15:24:45 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <ctime>
#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <deque>
#include "EasyFind.hpp"

#define SIZE 6

void printSetValue(const int& n) {
	std::cout << "Set<int> value: " << n << std::endl;
}

int randomNumberGenerator() {
	return std::rand() % (SIZE);
}

int main() {
	int value;

	std::srand(std::time(0));

	// ===== Sequence containers =====
	value = randomNumberGenerator();
	std::cout << "Generated value to find: " << value << std::endl;
	std::vector<int> myVector(SIZE);
	for (int i = 0; i <= SIZE; i++) {
		try {
			myVector.at(i) = randomNumberGenerator();
		} catch (const std::out_of_range& e) {}
	}
	for (std::vector<int>::size_type i = 0; i < myVector.size(); i++)
		std::cout << "Vector<int> value: " << myVector.at(i) << std::endl;
	std::vector<int>::iterator itVector = easyFind(myVector, value);
	if (itVector != myVector.end())
		std::cout << "The found value is: " << *itVector << std::endl;
	
	std::cout << std::endl;

	value = randomNumberGenerator();
	std::cout << "Generated value to find: " << value << std::endl;
	std::deque<int> myDeque;
	for (int i = 0; i < SIZE; i += 2) {
		myDeque.push_front(randomNumberGenerator());
		myDeque.push_back(randomNumberGenerator());
	}
	for (std::deque<int>::iterator itDeque = myDeque.begin(); itDeque != myDeque.end(); itDeque++)
		std::cout << "Deque<int> value: " << *itDeque << std::endl;
	std::deque<int>::iterator itDeque = easyFind(myDeque, value);
	if (itDeque != myDeque.end())
		std::cout << "The found value is: " << *itDeque << std::endl;
	// ============= End =============

	std::cout << std::endl;

	// ==== Associative container ====
	value = randomNumberGenerator();
	std::cout << "Generated value to find: " << value << std::endl;
	std::set<int> mySet;
	for (int i = 0; i < SIZE; i += 2)
		mySet.insert(randomNumberGenerator());
	std::for_each(mySet.begin(), mySet.end(), printSetValue);
	std::set<int>::iterator itSet = easyFind(mySet, value);
	if (itSet != mySet.end())
		std::cout << "The found value is: " << *itSet << std::endl;
	// ============= End =============

	std::cout << std::endl;

	// ===== Container adaptors =====
	value = randomNumberGenerator();
	std::cout << "Generated value to find: " << value << std::endl;
	std::stack 
	// ============= End =============
	
	return 0;
}
