/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   underlying_container.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:44:58 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/18 15:52:28 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <vector>

// Function to perform an action (for the sake of example)
void performAction(std::vector<int>& state, int action) {
    state.push_back(action);
}

// Function to undo the last action
void undoAction(std::vector<int>& state) {
    if (!state.empty()) {
        std::cout << "Undoing action: " << state.back() << std::endl;
        state.pop_back();
    } else {
        std::cout << "Nothing to undo." << std::endl;
    }
}

// Function to redo the last undone action
void redoAction(std::vector<int>& state, std::stack<int, std::vector<int> >& redoStack) {
    if (!redoStack.empty()) {
        int action = redoStack.top();
        redoStack.pop();
        std::cout << "Redoing action: " << action << std::endl;
        state.push_back(action);
    } else {
        std::cout << "Nothing to redo." << std::endl;
    }
}

int main() {
    std::vector<int> currentState;
    std::stack<int, std::vector<int> > undoStack;
    std::stack<int, std::vector<int> > redoStack;

    // Simulate user actions
    performAction(currentState, 10);
    performAction(currentState, 20);
    performAction(currentState, 30);

    // Display the current state
    std::cout << "Current State: ";
    for (std::vector<int>::iterator it = currentState.begin(); it != currentState.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Undo the last action
    undoAction(currentState);

    // Display the state after undo
    std::cout << "State after Undo: ";
    for (std::vector<int>::iterator it = currentState.begin(); it != currentState.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Redo the undone action
    redoStack.push(undoStack.top());
    undoStack.pop();
    redoAction(currentState, redoStack);

    // Display the state after redo
    std::cout << "State after Redo: ";
    for (std::vector<int>::iterator it = currentState.begin(); it != currentState.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
