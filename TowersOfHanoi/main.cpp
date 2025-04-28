#include <iostream>
#include "Stack.h"


void moveDisk(char fromRod, char toRod, int disk) {
    std::cout << "Move disk " << disk << " from rod " << fromRod << " to rod " << toRod << std::endl;
}

void showGameState(Stack &source, Stack &auxiliary, Stack &target, char sourceRod, char auxiliaryRod, char targetRod) {
    std::cout << sourceRod << ": ";
    source.display();
    std::cout << "\n" << auxiliaryRod << ": ";
    auxiliary.display();
    std::cout << "\n" << targetRod << ": ";
    target.display();
    std::cout << "\n" << "-----------------" << std::endl;
}

void solveTowersOfHanoi(int n) {
    Stack source, target, auxiliary;
    char sourceRod = 'A', targetRod = 'C', auxiliaryRod = 'B';

    // Initialize source stack with disks
    for (int i = n; i >= 1; --i) {
        source.push(i);
    }

    int totalMoves = (1 << n) - 1; // 2^n - 1

    // Display initial state
    std::cout << "Initial Game State:" << std::endl;
    showGameState(source, auxiliary, target, sourceRod, auxiliaryRod, targetRod);

    for (int i = 1; i <= totalMoves; ++i) {
        // std::cout << "Move number: " << i << std::endl;
        if (i % 3 == 1) {
            // std::cout << "Move between source and target" << std::endl;
            if (!source.isEmpty() && (target.isEmpty() || (source.peek() < target.peek()))) {
                target.push(source.pop());
                moveDisk(sourceRod, targetRod, target.peek());
            } else {
                source.push(target.pop());
                moveDisk(targetRod, sourceRod, source.peek());
            }
        } else if (i % 3 == 2) {
            // std::cout << "Move between source and auxiliary" << std::endl;
            if (!source.isEmpty() && (auxiliary.isEmpty() || source.peek() < auxiliary.peek())) {
                auxiliary.push(source.pop());
                moveDisk(sourceRod, auxiliaryRod, auxiliary.peek());
            } else {
                source.push(auxiliary.pop());
                moveDisk(auxiliaryRod, sourceRod, source.peek());
            }
        } else if (i % 3 == 0) {
            // std::cout << "Move between auxiliary and target" << std::endl;
            if (!auxiliary.isEmpty() && (target.isEmpty() || auxiliary.peek() < target.peek())) {
                target.push(auxiliary.pop());
                moveDisk(auxiliaryRod, targetRod, target.peek());
            } else {
                auxiliary.push(target.pop());
                moveDisk(targetRod, auxiliaryRod, auxiliary.peek());
            }
        }

        // Show game state after each move
        showGameState(source, auxiliary, target, sourceRod, auxiliaryRod, targetRod);
    }
}



int main() {
    int n; // Number of disks
    std::cout << "Enter the number of disks: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Number of disks must be greater than 0." << std::endl;
        return 1;
    }

    std::cout << "Steps to solve the Towers of Hanoi:" << std::endl;
    solveTowersOfHanoi(n);

    return 0;
}