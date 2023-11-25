/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:21:32 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/24 05:26:23 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int max_size) : _max_size(max_size), _span(NULL) {
	_span = new std::multiset<int>;
}

Span::Span(const Span& other)
	: _max_size(other._max_size), _span(new std::multiset<int>(*other._span)) {
}

Span::~Span() {
	delete _span;
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		delete _span;
		_max_size = other._max_size;
		_span = new std::multiset<int>(*other._span);
	}
	return *this;
}

void	Span::addNumber(int number) {
	if (_span->size() >= _max_size)
		throw SpanIsFull();
	_span->insert(number);
}

unsigned int	Span::shortestSpan() {
	if (_span->size() < 2)
		throw NotEnoughNumbers();
	unsigned int next;
	unsigned int prev;
	unsigned int shortest_span = 0;
	std::multiset<int>::iterator it = _span->begin();
	while (true) {
		prev = *it;
		std::advance(it, 1);
		if (it == _span->end())
			return shortest_span;
		next = *it;
		shortest_span = next - prev;
		if (shortest_span == 0)
			return 0;
	}
}

unsigned int	Span::longestSpan() {
	if (_span->size() < 2)
		throw NotEnoughNumbers();
	return (*(--_span->end()) - *(_span->begin()));
}

// Develop a Span class that can store a maximum of N integers. 
// N is an unsigned int variable and will be the only parameter passed to the constructor.

// This class will have a member function called addNumber() to add a single number to the Span.
// It will be used in order to fill it. Any attempt to add a new element if there are
// already N elements stored should throw an exception.

// Next, implement two member functions: shortestSpan() and longestSpan().
// They will respectively find out the shortest span or the longest span (or distance, if
// you prefer) between all the numbers stored, and return it. If there are no numbers stored,
// or only one, no span can be found. Thus, throw an exception.

// Of course, you will write your own tests and they will be way more thorough than the
// ones below. Test your Span at least with a minimum of 10 000 numbers. More would be
// even better.
