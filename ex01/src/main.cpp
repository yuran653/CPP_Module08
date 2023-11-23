/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:20:39 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/23 19:38:08 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Span.hpp"

#define SIZE 10

int randomNumberGenerator() {
	return std::rand() % (SIZE);
}

int main () {
	std::srand(std::time(0));

	Span span(SIZE);
	for (int i = 0; i < SIZE; i++) {
		span.addNumber(randomNumberGenerator());
	}
	try {
		std::cout << "The longest span is: " << span.longestSpan() << std::endl;
	span.longestSpan();
	} catch (const std::exception& e) {};

	return 0;
}
