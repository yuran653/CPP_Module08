/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:19:26 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/16 19:43:47 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "EasyFind.hpp"

struct my_value_not_found : std::exception {
	const char* what() const throw {
		return "The value not found";
	}
};

template <typename T>
typename T::iterator easyFind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw my_value_not_found();
	return it;
}

#endif