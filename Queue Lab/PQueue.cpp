/*
 * LaQueue
 * 
 * 
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *  
 * (c) copyright 2018, James Shockey - all rights reserved
 * 
 * */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"



/*
 * Class Priority Queue
 */

		
/*
* Insert into Priority Queue
*/
void PQueue::push(void *itm, int pri) {
    node *temp, *queue;
    temp = new node;
    temp->data = itm;
    temp->priority = pri;
    temp->link = nullptr; 

    if (front == nullptr || pri < front->priority) {
        temp->link = front;
        front = temp;
    } else {
        queue = front;
        while (queue->link != nullptr && queue->link->priority < pri) {
            queue = queue->link;
        }
        temp->link = queue->link;
        queue->link = temp;
    }
}

/*
 * Show top of Priority Queue
 */
void* PQueue::top() {
	if(front == NULL) {
		std::cout<<"Queue Underflow\n";
	}
	// returns the top of the queue
	return front->data;
}

/*
 * Delete from Priority Queue
 */
void PQueue::pop()
{
	// pops the top of the queue
	node *temp;
	if(front == NULL) {
		std::cout<<"Queue Underflow\n";
	} else {
		temp = front;
		std::cout<<"Deleted item is: "<<(char*)temp->data<<std::endl;
		front = front->link;
		free(temp);
	}
}

/*
 * Print Priority Queue
 */
void PQueue::display()
{
	// loops through the queue and prints the priority and data
	node *ptr;
	ptr = front;
	if (front == NULL) {
		std::cout<<"Queue is empty\n";
	} else {
		while(ptr != NULL) {
			std::cout<<ptr->priority<<" "<<(char*)ptr->data<<std::endl;
			ptr = ptr->link;
		}
	}
}
	