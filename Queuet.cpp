//
// Created by Kareem Elnaghy on 10/23/23.
//

#include "Queuet.h"
#include <iostream>
using namespace std;
// Constructor with argument, size is nelements, default 128
template <class Type>
Queuet<Type>::Queuet(int nelements)
{  MaxSize = nelements; queue = new Type[MaxSize];
    front = 1; rear = 0; count = 0;
}

// Copy Constructor
template <class Type>
Queuet<Type>::Queuet (const Queuet<Type> &original)
        :MaxSize(original.MaxSize), front(original.front), rear(original.rear), count(original.count)
{
    queue = new Type[MaxSize];
    for (int i = 0; i < MaxSize; i++) queue[i] = original.queue[i];
}


// Destructor
template <class Type>
Queuet<Type>::~Queuet()
{ delete [] queue;}

// Add to rear
template <class Type>
void Queuet<Type>::enqueue(Type v)
{
    if(queueIsFull()) cout << "Queue is Full" << endl;
    else
    {
        rear = (rear + 1) % MaxSize;
        queue[rear] = v;  count++;
    }
}

// Remove from front
template <class Type>
void Queuet<Type>::dequeue(Type &v)
{
    if(queueIsEmpty()) cout << "Queue is Empty" << endl;
    else
    {
        v = queue[front];
        front = (front + 1) % MaxSize; count--;
    }
}

// Retrieve front without removing it
template <class Type>
void Queuet<Type>::queueFront(Type &v) const
{
    if(queueIsEmpty()) cout << "Queue is Empty" << endl;
    else 	v = queue[front];
}

// Test for Empty queue
template <class Type>
bool Queuet<Type>::queueIsEmpty() const
{ return (count == 0); }

// Test for Full queue
template <class Type>
bool Queuet<Type>::queueIsFull() const
{ return (count == MaxSize); }

// Queue Length
template <class Type>
int Queuet<Type>::queueLength() const
{ return count; }