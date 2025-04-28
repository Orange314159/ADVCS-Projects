//*****************************************************************
//  LinkedList.cpp
//  HashTable

//
//  This header file contains the Linked List class declaration.
//  Hash Table array elements consist of Linked List objects.
//*****************************************************************

#include "LinkedList.h"

// Constructs the empty linked list object.
// Creates the head node and sets length to zero.
LinkedList::LinkedList()
{
    head = NULL;
    length = 0;
}

// Inserts an item at the end of the list.
void LinkedList::insert( Element* newElement ) {
  if (head == NULL) {
    head = newElement;
  } else {
    Element* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newElement;
  }
  length++;
}

// Removes an item from the list by item key.
// Returns true if the operation is successful.
bool LinkedList::remove( string Key ) {
  if (head == NULL) return false; 

  Element* current = head;
  Element* previous = NULL;

  while (current != NULL) {
    if (current->key == Key) {
      if (previous == NULL) {
        head = current->next;
      } else {
        previous->next = current->next;
      }
      delete current;
      length--;
      return true;
    }
    previous = current;
    current = current->next;
  }
  return false; // item not found (so not removed and unsuccessful)
}

// Searches for an item by its key.
// Returns a reference to first match.
// Returns a NULL pointer if no match is found.
Element * LinkedList::get( string Key ) {
  Element * p = head;
  while (p != NULL) {
    if (p->key == Key) {
      return p;
    }
    p = p->next;
  }
  return nullptr; // item not found
}

// Displays list contents to the console window.
void LinkedList::printList()
{
    if (length == 0)
    {
        cout << "\n{ }\n";
        return;
    }
    Element * p = head;
    Element * q = head;
    cout << "\n{ ";
    while (q)
    {
        p = q;
        //if (p != head)
        if (p != nullptr)
        {
            cout << p -> key;
            if (p -> next) cout << ", ";
            else cout << " ";
        }
        q = p -> next;
    }
    cout << "}\n";
}

// Returns the length of the list.
int LinkedList::getLength() {
  return length;
}

// De-allocates list memory when the program terminates.
LinkedList::~LinkedList() {
  Element* current = head;
  while (current != NULL) {
    Element* next = current->next;
    delete current;
    current = next;
  }
  length = 0;
  head = NULL; 
}

//*****************************************************************
// End of File
//*****************************************************************