#ifndef PQUEUE_H
#define PQUEUE_H

#include "linkedQueue.h"

template <class t>
class fakePriorityQueue : public linkedQueue<t>
{
public:
    void enqueue(const t &);
};

template <class t>
void fakePriorityQueue<t>::enqueue(const t &queueElement)
{
    node<t> *newNode = new node<t>;            //make new node
    newNode->data = new t(queueElement);
    newNode->link = nullptr;

    if (this->isEmptyQueue()){
        this->queueFront = newNode;            //if empty both pointers point at the first new node
        this->queueRear = newNode;
    }
    else{
        node<t> *current = this->queueFront;        //current points to the front
        node<t> *previous = nullptr;                //previous points to the end

        while (current != nullptr && queueElement <= *(current->data)){
            previous = current;                    //this loop traverses the list comparing data
            current = current->link;
        }

        if (previous == nullptr){                   //insert at the front if loop completed(back to nullptr)
            newNode->link = this->queueFront;
            this->queueFront = newNode;
        }
        else{                                         //insert whereever *current landed
            newNode->link = current;
            previous->link = newNode;
        }

        if (newNode->link == nullptr)                //update queueRear if the new node was at the end
        {
            this->queueRear = newNode;
        }
    }
}

#endif
