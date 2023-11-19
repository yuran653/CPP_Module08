/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:19:26 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/19 17:56:25 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "EasyFind.hpp"

// template <typename T>
// typename T::iterator easyFind(T& container, int value) {
// 	typename T::iterator it = std::find(container.begin(), container.end(), value);
// 	if (it == container.end())
// 		std::cerr << "The value is not found" << std::endl;
// 	return it;
// }

template <typename T>
typename T() easyFind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		std::cerr << "The value is not found" << std::endl;
	return it;
}

#endif