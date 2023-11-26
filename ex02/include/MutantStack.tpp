/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:22:40 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/26 16:39:24 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <class T, class Container>
MutantStack<T, Container>::MutantStack() {
};

template <class T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other)
	: _underlying_cont(other._underlying_cont) {
}

template <class T, class Container>
MutantStack<T, Container>::~MutantStack() {
}

template <class T, class Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack<T, Container>& other) {
	if (this != &other)
		_underlying_cont = other._underlying_cont;
	return *this;
}

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
	return _underlying_cont.begin();
}

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end(){
	return _underlying_cont.end();
}

template <class T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin() {
	return _underlying_cont.rbegin();
}

template <class T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend(){
	return _underlying_cont.rend();
}

template <class T, class Container>
T& MutantStack<T, Container>::top() {
	return _underlying_cont.front();
}

template <class T, class Container>
const T& MutantStack<T, Container>::top() const{
	return _underlying_cont.front();
}

template <class T, class Container>
bool MutantStack<T, Container>::empty() const {
	return _underlying_cont.empty();
}

template <class T, class Container>
size_t MutantStack<T, Container>::size() const {
	return _underlying_cont.size();
}

template <class T, class Container>
void MutantStack<T, Container>::push(const T& value) {
	_underlying_cont.insert(_underlying_cont.begin(), value);
}

template <class T, class Container>
void MutantStack<T, Container>::pop() {
	_underlying_cont.erase(_underlying_cont.begin());
}

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
