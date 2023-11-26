/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:23:15 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/26 18:33:29 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include "MutantStack.hpp"

#define SIZE 20
#define RANGE 9

int randomNumberGenerator() {
	return std::rand() % (RANGE);
}

int main () {
	std::srand(std::time(0));

	int mutant_size;
	int stack_size;

	MutantStack<int> mutant_1;
	std::stack<int> stack_1;
	std::cout << "\'MutantStack<int>\' \'mutant_1\' and \'std::stack\' \'stack_1\' are initialized" << std::endl;

	std::cout << "Method \'push(randomNumberGenerator())\' will be applied to \'mutant_1\' and \'stack_1\'" << std::endl;
	int random;
	for (int i = 0; i < SIZE; i++) {
		random = randomNumberGenerator();
		mutant_1.push(random);
		stack_1.push(random);
	}

	mutant_size = mutant_1.size();
	stack_size = stack_1.size();

	if (mutant_size == stack_size) {
		std::cout << "Sizes of \'mutant_1\' and \'stack_1\' are equal: OK" << std::endl;
		std::cout << "Print vslues of \'mutant_1\' using \'iterator\' \'begin()\\end()\' in \'for\' loop:" << std::endl;
		for (MutantStack<int>::iterator it = mutant_1.begin(); it != mutant_1.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << "Print values of \'mutant_1\' using \'iterator\' \'rbegin()\\rend()\' in \'for\' loop:" << std::endl;
		for (MutantStack<int>::reverse_iterator it = mutant_1.rbegin(); it != mutant_1.rend(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << "Methods \'top()\' and \'pop()\' will be applied to \'mutant_1\' and \'stack_1\' in \'while\' loop using condition \'empty() != 0\'" << std::endl;
		while (mutant_1.empty() == false || stack_1.empty() == false) {
			std::cout << "Top elemants of \'mutant_1\' and \'stack_1\' should be equal: "
				<< mutant_1.top() << " == " << stack_1.top() << std::endl;
			if (mutant_1.top() != stack_1.top()) {
				std::cerr << "Top elemants of \'mutant_1\' and \'stack_1\' are NOT equal: KO" << std::endl;
				return 1;
			}
			mutant_1.pop();
			stack_1.pop();
		}
		if (mutant_1.empty() == false ) {
			std::cerr << "\'mutant_1\' is NOT empty: KO" << std::endl;
			if (stack_1.empty() == false) {
				std::cerr << "\'stack_1\' is NOT empty: KO" << std::endl;
			return 1;
		}
		else
			std::cout 
	}
	else {
		std::cerr << "Sizes of \'mutant_1\' and \'stack_1\' are NOT equal: KO" << std::endl;
		return 1;
	}

	return 0;
}
