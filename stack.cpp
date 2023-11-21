/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:36:27 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/21 13:30:09 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <vector>
#include <list>

int main() {
    std::stack<int, std::list<int> > myStack;

    for (int i = 0; i < 5; ++i) {
        myStack.push(i);
    }

    // Access the underlying container (std::vector in this case)
    std::list<int>& myVector = *reinterpret_cast<std::list<int>*>(&myStack);

    // Now you can iterate through the elements using iterators
    for (std::list<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
        std::cout << *it << " " << std::endl;
    }

    std::cout << "Stack top: " << myStack.top() << std::endl;

    return 0;
}
