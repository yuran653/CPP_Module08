/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:43:06 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/15 19:44:14 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main() {
	std::vector<char> myVector(10, 0);

	int prev_i = 65;
	for (size_t i = 0; true; i++) {
		try {
			myVector.at(i) = prev_i + i;
			prev_i += i;
			std::cout << "At index[" << i << "] ASCII #" << prev_i << std::endl;
		} catch (std::out_of_range& e) {
			break;
		}
	}
	// Using begin() and end() iterators for traversal
	for (std::vector<char>::iterator it = myVector.begin(); it != myVector.end(); it++) {
		std::cout << *it << std::endl;
	}

	return 0;
}