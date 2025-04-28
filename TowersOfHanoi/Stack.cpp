#include "Stack.h"
#include <string>

using namespace std;

Node* top;
int size;

Stack::Stack(){
    this->top = nullptr;
    this->size = 0; 
}
Stack::~Stack(){
    while (top != nullptr){
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}
void Stack::push(int d){

    // initialize the new node of the stack
    Node* newNode = new Node;
    newNode->data = d;
    newNode->next = top;

    // add node to stack
    top = newNode;

    // incriment size
    size++;
}
int Stack::pop(){
    if (size < 1){
        // stack underflow
        cout << "Error: stack underflow";
    }

    Node* temp = top;
    top = top->next;
    size--;
    return temp->data;
}
int Stack::peek() const{
    if (size < 1){
        // stack underflow
        cout << "Error: stack underflow";
    }
    return top->data;
}
bool Stack::isEmpty() const{
    return size == 0;
}
void Stack::display() {
    Node* temp = top;
    string s = "";
    while (temp != nullptr){
        // cout << temp->data << " ";
        s = to_string(temp->data) + " " + s;
        temp = temp->next;
    }
    cout << s;
}
// void moveDisk(char sourceRod, char targetRod, int disk) {
//     cout << "Move disk " << disk << " from " << sourceRod << " to " << targetRod << endl;
// }
// Soumik rocks!

