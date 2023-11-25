/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:21:07 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/25 20:36:05 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <set>

class Span {
	private:
		unsigned int			_max_size;
		std::multiset<int>*		_span;

	public:
		Span(unsigned int max_size);
		Span(const Span& other);
		~Span();

		Span& operator=(const Span& other);

		void			addNumber(int number);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		
	class SpanIsFull : public std::exception {
		public:
			const char* what() const throw() {
				return "The span is full";
			}
	};
	
	class NotEnoughNumbers : public std::exception {
		public:
			const char* what() const throw() {
				return "Not enough numbers in the span";
			}
	};
};

#endif
