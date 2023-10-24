//
// Created by Kareem Elnaghy on 10/23/23.
//

#include "Stackt.h"
// File: Stackt.cpp
// Stack template class implementation

#include <iostream>
using namespace std;


// Constructor with argument, size is nelements, default is 128
template <class Type>
Stackt<Type>::Stackt(int nelements)
{  MaxSize = nelements; stack = new Type[MaxSize];  top = -1; }

// Copy Constructor
template <class Type>
Stackt <Type>::Stackt(const Stackt<Type> &original)
        :MaxSize(original.MaxSize), top(original.top)
{
    stack = new Type[MaxSize];
    for (int i = 0; i <= top; i++) stack[i] = original.stack[i];
}


// Destructor
template <class Type>
Stackt<Type>::~Stackt()
{ delete [] stack;}

// Push
template <class Type>
void Stackt<Type>::push(Type v)
{
    if(stackIsFull()) cout << "Stack Overflow" << endl;
    else stack[++top] = v;
}

// Pop
template <class Type>
void Stackt<Type>::pop(Type &v)
{
    if(stackIsEmpty()) cout << "Stack Underflow" << endl;
    else v = stack[top--];
}

// Retrieve stack top without removing it
template <class Type>
void Stackt<Type>::stackTop(Type &v) const
{
    if(stackIsEmpty()) cout << "Stack Underflow";
    else v = stack[top];
}

// Test for Empty stack
template <class Type>
bool Stackt<Type>::stackIsEmpty() const
{ return (top < 0); }

// Test for Full stack
template <class Type>
bool Stackt<Type>::stackIsFull() const
{ return (top >= (MaxSize-1)); }

