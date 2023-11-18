/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:36:27 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/18 15:37:14 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <vector>

int main() {
    // Creating a stack of integers using a vector as the underlying container
    std::stack<int, std::vector<int> > myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Top element: " << myStack.top() << std::endl;
    myStack.pop();
    std::cout << "After popping, new top element: " << myStack.top() << std::endl;

    return 0;
}