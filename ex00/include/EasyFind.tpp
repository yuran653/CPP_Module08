/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:19:26 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/17 19:10:24 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include <stdexcept>
#include "EasyFind.hpp"

class value_not_found : public std::exception {
	public:
		const char* what() const throw() {
			return "The value not found";
	}
};

template <typename T>
typename T::iterator easyFind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw value_not_found();
	return it;
}

#endif