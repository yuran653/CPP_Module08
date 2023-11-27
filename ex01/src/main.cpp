/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:20:39 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/27 16:01:16 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
#include <ctime>
#include <cstdlib>
#include "Span.hpp"

#define MAX_SIZE 1000000
#define NUMBERS 1000000

int randomNumberGenerator() {
	return std::rand() % (INT_MAX);
}

int main () {
	std::srand(std::time(0));

	// Span test_exception(MAX_SIZE);
	// test_exception.addNumber(1);
	// try {
	// 	std::cout << "The shortest span1 is: " << test_exception.shortestSpan() << std::endl;
	// } catch (const Span::SpanIsFull& e) {
	// 	std::cerr << "Exception caught: " << e.what() << std::endl;
	// }

	std::cout << std::endl;

	Span span1(MAX_SIZE);
	try {
		span1.addNumber(10);
	} catch (const Span::SpanIsFull& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try {
		std::cout << "The shortest span1 is: " << span1.shortestSpan() << std::endl;
	} catch (const Span::NotEnoughNumbers& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	};
	try {
		std::cout << "The longest span1 is: " << span1.longestSpan() << std::endl;
	} catch (const Span::NotEnoughNumbers& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	};
	try {
		span1.addNumber(10);
		span1.addNumber(20);
		span1.addNumber(30);
	} catch (const Span::SpanIsFull& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try {
		std::cout << "The shortest span1 is: " << span1.shortestSpan() << std::endl;
	} catch (const Span::NotEnoughNumbers& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	};
	try {
		std::cout << "The longest span1 is: " << span1.longestSpan() << std::endl;
	} catch (const Span::NotEnoughNumbers& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	};

	std::cout << std::endl;

	Span span2(span1);
	try {
		while (true) {
		span2.addNumber(randomNumberGenerator());
		span2.addNumber(-randomNumberGenerator());
		}
	} catch (const Span::SpanIsFull& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	Span span3(0);
	try {
		std::cout << "The shortest span3 is: " << span3.shortestSpan() << std::endl;
	} catch (const Span::NotEnoughNumbers& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	};
	try {
		std::cout << "The longest span3 is: " << span3.longestSpan() << std::endl;
	} catch (const Span::NotEnoughNumbers& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	};
	span3 = span2;
	try {
		std::cout << "The shortest span1 is: " << span1.shortestSpan() << std::endl;
		std::cout << "The shortest span2 is: " << span2.shortestSpan() << std::endl;
		std::cout << "The shortest span3 is: " << span3.shortestSpan() << std::endl;
	} catch (const Span::NotEnoughNumbers& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	};
	try {
		std::cout << "The longest span1 is: " << span1.longestSpan() << std::endl;
		std::cout << "The longest span2 is: " << span2.longestSpan() << std::endl;
		std::cout << "The longest span3 is: " << span3.longestSpan() << std::endl;
	} catch (const Span::NotEnoughNumbers& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	};

	std::cout << std::endl;

	Span span(MAX_SIZE);
	try {
		for (int i = 0; i < NUMBERS; i++) {
			span.addNumber(i);
		}
	} catch (const Span::SpanIsFull& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try {
		std::cout << "The shortest span is: " << span.shortestSpan() << std::endl;
	} catch (const Span::NotEnoughNumbers& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	};
	try {
		std::cout << "The longest span is: " << span.longestSpan() << std::endl;
	} catch (const Span::NotEnoughNumbers& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	};

	std::cout << std::endl;

	return 0;
}
