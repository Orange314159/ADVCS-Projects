#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <iostream>

// <<<< Your code here >>>>

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
    int size;

public:
    Stack();
    ~Stack();
    void push(int data);
    int pop();
    int peek() const;
    bool isEmpty() const;
    void display();
};

#endif // STACK_H