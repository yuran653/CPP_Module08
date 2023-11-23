/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:21:07 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/22 19:28:48 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <set>

class Span {
	private:
		unsigned int					_size;
		std::multiset<int>*				_span;
		// std::multiset<int>::iterator	it1;

	public:
		Span(unsigned int size);
		Span(const Span& other);
		~Span();

		Span& operator=(const Span& other);

		void			addNumber(int number);
		// unsigned int	shortestSpan();
		unsigned int	longestSpan();
	
	class SpanSizeError : public std::exception {
		const char* what() const throw() {
			return "Not enough numbers in the span";
		}
	};
};

#endif
