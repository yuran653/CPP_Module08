/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:18:49 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/17 19:44:54 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include "EasyFind.hpp"

#define SIZE 6

int main() {
	int value;

	std::srand(std::time(0));
	value = std::rand() % 7;
	std::cout << "Generated value to find: " << value << std::endl;
	std::vector<int> myVector(SIZE);
	for (int i = 0; i <= SIZE; i++) {
		try {
			myVector.at(i) = i;
		} catch (const std::out_of_range& e) {}
	}
	try {
		for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++)
			std::cout << "Vector<int> value: " << *it << std::endl;
		std::vector<int>::iterator it = easyFind(myVector, value);
		std::cout << "Value found is: " << *it << std::endl;
	} catch (const value_not_found& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::srand(std::time(0));
	value = std::rand() % 7;
	std::cout << "Generated value to find: " << value << std::endl;
	std::deque<int> myDeque;
	for (int i = 0; i < SIZE; i += 2) {
		myDeque.push_front(i);
		myDeque.push_back(i + 1);
	}
	try {
		for (std::deque<int>::iterator it = myDeque.begin(); it != myDeque.end(); it++)
			std::cout << "Deque<int> value: " << *it << std::endl;
		std::deque<int>::iterator it = easyFind(myDeque, value);
		std::cout << "Value found is: " << *it << std::endl;
	} catch (const value_not_found& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
