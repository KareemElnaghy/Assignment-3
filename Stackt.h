//
// Created by Kareem Elnaghy on 10/23/23.
//

#ifndef ADS_ASSIGNMENT_3_STACKT_H
#define ADS_ASSIGNMENT_3_STACKT_H


// File: Stackt.h
// Stack template class definition.
// Dynamic array implementation


template <class Type>

class Stackt
{
public:

    Stackt(int nelements = 128);		// Constructor
    Stackt (const Stackt<Type> &);	// Copy Constructor
    ~Stackt();						// Destructor

    // Member Functions
    void push(Type );				// Push
    void pop(Type &);				// Pop
    void stackTop(Type &) const;	// retrieve top
    bool stackIsEmpty() const;	// Test for Empty stack
    bool stackIsFull() const;		// Test for Full stack

private:
    Type *stack;					// pointer to dynamic array
    int top, MaxSize;

};







#endif //ADS_ASSIGNMENT_3_STACKT_H
