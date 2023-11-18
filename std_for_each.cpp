/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_for_each.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:34:40 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/18 14:39:58 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <set>
#include <algorithm>

void printSetValue(const int& n) {
	std::cout << "Set<int> value: " << n << std::endl;
}

int main() {
	std::set<int> mySet;
	for (int i = 0; i < 5; i++)
		mySet.insert(i);

	std::for_each(mySet.begin(), mySet.end(), printSetValue);
	return 0;
}
