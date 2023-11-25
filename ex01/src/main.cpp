/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:20:39 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/24 05:27:34 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include "Span.hpp"

#define MAX_SIZE 1000000
#define NUMBERS 10000000

int randomNumberGenerator() {
	return std::rand() % (INT_MAX);
}

int main () {
	std::srand(std::time(0));

	Span span(MAX_SIZE);
	try {
		for (int i = 0; i < NUMBERS; i++) {
		// span.addNumber(randomNumberGenerator());
		// span.addNumber(-randomNumberGenerator());
		// span.addNumber(i);
		span.addNumber(10);
		span.addNumber(20);
		}
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "The shortest span is: " << span.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	};
	
	try {
		std::cout << "The longest span is: " << span.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	};

	return 0;
}
