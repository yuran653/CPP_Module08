/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:22:50 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/26 18:01:34 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <list>
#include <stack>
#include <vector>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	private:
		Container _underlying_cont;

	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		~MutantStack();

		MutantStack& operator=(const MutantStack& other);

		typedef typename Container::iterator iterator;
		iterator			begin();
		iterator			end();

		typedef typename Container::reverse_iterator reverse_iterator;
		reverse_iterator	rbegin();
		reverse_iterator	rend();

		T&					top();
		const T&			top() const;
		bool				empty() const;
		size_t				size() const;
		void				push(const T& value);
		void				pop();
};

#include "MutantStack.tpp"

#endif

// Now, time to move on more serious things. Let’s develop something weird.
// The std::stack container is very nice. Unfortunately, it is one of the only
// STL Containers that is NOT iterable. That’s too bad. But why would we accept this?
// Especially if we can take the liberty of butchering the original stack to create
// missing features.

// To repair this injustice, you have to make the std::stack container iterable.

// Write a MutantStack class. It will be implemented in terms of a std::stack.
// It will offer all its member functions, plus an additional feature: iterators.

// Of course, you will write and turn in your own tests to ensure everything works as
// expected
